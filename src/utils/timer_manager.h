#ifndef TIMER_H
#define TIMER_H
#include <functional>

class TimerManager
{
public:
    void CreateTimedFunction(float ttl, const std::function<void()>& callback);

    void UpdateTimers(float deltaTime);

private:
    struct TimedFunction
    {
        float elapsed{0.0f};
        float ttl;
        bool done{false};
        std::function<void()> callback;
    };

    std::vector<TimedFunction> functionTimers{};
};


#endif //TIMER_H
