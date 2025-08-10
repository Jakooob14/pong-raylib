#ifndef FUNCTION_TIMER_H
#define FUNCTION_TIMER_H
#include <functional>


class FunctionTimer
{
public:
    FunctionTimer(const float ttl, const std::function<void()>& callback) :
        ttl(ttl), callback(callback)
    {}

    float GetElapsed() const { return elapsed; }
    void AddElapsed(const float deltaTime) { elapsed += deltaTime; }
    float GetTtl() const { return ttl; }
    bool IsDone() const { return done; }
    void SetDone(const bool value) { done = value; }

    void InvokeCallback() const;
    void Reset();

private:
    float elapsed{0.0f};
    float ttl{0.0f};
    bool done{false};
    std::function<void()> callback{};
};



#endif //FUNCTION_TIMER_H
