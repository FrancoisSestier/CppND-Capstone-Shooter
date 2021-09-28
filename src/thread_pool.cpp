
#include <thread_pool.hpp>

void ThreadPool::ThreadLoop()
{
    std::function<void()> task;
    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(mutex_);

            cv.wait(lock);

            if (task_queue_.empty())
            {
                return;
            }
            task = std::move(task_queue_.front());
            task_queue_.pop();
        }
        task();
    }
}

ThreadPool::ThreadPool(uint32_t thread_count) {
    for (uint32_t i = 0; i < thread_count; i++)
    {
        threads_.push_back(std::thread(&ThreadPool::ThreadLoop,this));
    }
}

ThreadPool::~ThreadPool(){
    {
        const std::scoped_lock<std::mutex> lock(mutex_);
        while(!task_queue_.empty()){
            task_queue_.pop();
        }
    }
    cv.notify_all();
    for(auto& thread : threads_) {
        thread.join();
    }
    threads_.clear();
}