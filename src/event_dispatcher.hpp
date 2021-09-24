#pragma once
#include <functional>
#include <event.hpp>
#include <vector>

class EventDispatcher
{
public:
  void Dispatch() const;

  void RegisterKeyEventCallback(std::function<void(KeyEvent)> callback);

  void RegisterQuitCallback(std::function<void()> callback);

private:

  void DispatchKeyEvent(KeyEvent) const;

  std::vector<std::function<void(KeyEvent)>> key_event_callbacks_;
  std::function<void()> quit_callback_{nullptr};
};
