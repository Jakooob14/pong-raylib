#include "paddle.h"

#include <cstdio>
#include <raylib.h>

#include "../utils/input.h"


Paddle::Paddle(const PlayerId player, const float x, const float y) :
    x(x), y(y), player(player)
{}

Rectangle Paddle::GetBoundingBox()
{
    return {x, y, static_cast<float>(width), static_cast<float>(height)};
}

void Paddle::Update()
{
    float speedTime{speed * GetFrameTime()};

    if (input::IsMoveUp(player)) y -= speedTime;
    if (input::IsMoveDown(player)) y += speedTime;

    // Clamp to screen
    if (y < 0) y = 0;
    if (y > GetScreenHeight() - height) y = GetScreenHeight() - height;
}

void Paddle::Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}
