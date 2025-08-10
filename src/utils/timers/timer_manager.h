#ifndef TIMER_H
#define TIMER_H
#include <functional>
#include <memory>

#include "function_timer.h"

class TimerManager
{
public:
    void StartTimedFunction(const std::shared_ptr<FunctionTimer> &functionTimer);
    void UpdateTimers(float deltaTime);

private:
    std::vector<std::shared_ptr<FunctionTimer>> functionTimers{};
};


#endif //TIMER_H
