#include "timer_manager.h"

void TimerManager::StartTimedFunction(const std::shared_ptr<FunctionTimer>& functionTimer)
{
    functionTimers.push_back(functionTimer);
}

void TimerManager::UpdateTimers(const float deltaTime)
{
    for (const auto& timer: functionTimers)
    {
        timer->AddElapsed(deltaTime);
        if (timer->GetElapsed() >= timer->GetTtl())
        {
            timer->InvokeCallback();
            timer->SetDone(true);

            // Remove ended timer
            std::erase_if(
                functionTimers,
                [](const std::shared_ptr<FunctionTimer>& t){ return t->IsDone(); });
        }
    }
}
