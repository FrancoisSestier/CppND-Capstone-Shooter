#pragma once
#include <functional>
#include <input.hpp>
#include <vector>

class EventDispatcher
{
public:
  void Dispatch() const;

  void RegisterKeyDownCallback(std::function<void(Key)> callback);

  void RegisterQuitCallback(std::function<void()> callback);

private:

  void DispatchKeyDown(Key key) const;

  std::vector<std::function<void(Key)>> key_down_callbacks_;
  std::function<void()> quit_callback_{nullptr};
};
