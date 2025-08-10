#include "function_timer.h"

#include "../../core/globals.h"

void FunctionTimer::InvokeCallback() const
{
    if (callback) callback();
}

void FunctionTimer::Reset()
{
    elapsed = 0.0f;
    done = false;
}

