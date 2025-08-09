#include "random.h"

#include <random>

#include "../core/globals.h"


int GetRandomInt(const int min, const int max)
{
    std::uniform_int_distribution dist{min, max};
    return dist(rng);
}

double GetRandomDouble(const double min, const double max)
{
    std::uniform_real_distribution dist{min, max};
    return dist(rng);
}

double GetRandomDouble(const double min, const double max, int decimals)
{
    return std::round(GetRandomDouble(min, max) * std::pow(10, decimals)) / std::pow(10, decimals);
}

bool GetRandomBool()
{
    return GetRandomInt(0, 1) == 1;
}
