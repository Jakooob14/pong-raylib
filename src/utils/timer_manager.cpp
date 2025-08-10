#include "timer_manager.h"

void TimerManager::CreateTimedFunction(const float ttl, const std::function<void()>& callback)
{
    TimedFunction timedFunction{};
    timedFunction.ttl = ttl;
    timedFunction.callback = callback;

    functionTimers.push_back(timedFunction);
}

void TimerManager::UpdateTimers(const float deltaTime)
{
    for (auto& timer: functionTimers)
    {
        timer.elapsed += deltaTime;
        if (timer.elapsed >= timer.ttl)
        {
            if (timer.callback) timer.callback();
            timer.done = true;

            // Remove ended timer
            std::erase_if(
                functionTimers,
                [](const TimedFunction& t){ return t.done; });
        }
    }
}
