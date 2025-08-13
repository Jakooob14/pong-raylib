#ifndef FUNCTION_TIMER_H
#define FUNCTION_TIMER_H
#include <functional>


class FunctionTimer
{
public:
    FunctionTimer(const float ttl, const std::function<void()>& callback) :
        ttl(ttl), callback(callback)
    {}

    [[nodiscard]] float GetElapsed() const { return elapsed; }
    void AddElapsed(const float deltaTime) { elapsed += deltaTime; }
    [[nodiscard]] float GetTtl() const { return ttl; }
    [[nodiscard]] bool IsDone() const { return done; }
    void SetDone(const bool value) { done = value; }

    void InvokeCallback() const;
    void Reset();

private:
    float elapsed{0.0f};
    float ttl{0.0f};
    bool done{false};
    std::function<void()> callback{nullptr};
};



#endif //FUNCTION_TIMER_H
