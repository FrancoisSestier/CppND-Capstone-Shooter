#pragma once
#include <thread>
#include <queue>
#include <functional>
#include <future>
#include <mutex>
#include <condition_variable>
#include <type_traits>

class ThreadPool
{
public:
    ThreadPool(uint32_t thread_count = std::thread::hardware_concurrency());
    ~ThreadPool();

    ThreadPool(ThreadPool &&other) = delete;
    ThreadPool(const ThreadPool &other) = delete;

    ThreadPool &operator=(ThreadPool &&other) = delete;
    ThreadPool &operator=(const ThreadPool &other) = delete;

    //template <typename F, typename... Args>
    //std::future<typename std::result_of<F(Args...)>::type> push(const F &task, const Args &...args);

    template <typename F, typename C, typename... Args, typename Ret = std::invoke_result_t<F, C, Args...>, typename = std::enable_if_t<std::is_member_function_pointer_v<F>>, typename = std::enable_if_t<std::is_void_v<Ret>>>
    std::future<void> push(F task, C c, const Args &...args)
    {
        std::shared_ptr<std::promise<Ret>> promise = std::make_shared<std::promise<Ret>>();
        std::future<Ret> future = promise->get_future();
        push([c, task, promise, args...]
             {
                 std::invoke(task, *c, args...);
                 promise->set_value();
             });
        return future;
    }

    template <typename F, typename C, typename... Args, typename Ret = std::invoke_result_t<F, C, Args...>, typename = std::enable_if_t<std::is_member_function_pointer_v<F>>, typename = std::enable_if_t<!std::is_void_v<Ret>>>
    std::future<Ret> push(F task, C c, const Args &...args)
    {
        std::shared_ptr<std::promise<Ret>> promise = std::make_shared<std::promise<Ret>>();
        std::future<Ret> future = promise->get_future();
        push([c, task, promise, args...]
             { promise->set_value(std::invoke(task, *c, args...)); });
        return future;
    }

    template <typename F>
    void push(const F &task);

private:
    void ThreadLoop();

    std::queue<std::function<void()>> task_queue_;
    std::vector<std::thread> threads_;
    mutable std::mutex mutex_;
    std::condition_variable cv;
    std::atomic_bool running;
};

template <typename F>
void ThreadPool::push(const F &task)
{
    {
        const std::scoped_lock<std::mutex> lk(mutex_);
        task_queue_.push(std::function<void()>(task));
    }
    cv.notify_one();
}
