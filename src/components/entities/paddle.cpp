#include "paddle.h"

#include <cstdio>
#include <raylib.h>

#include "../../utils/input.h"


Paddle::Paddle(const PlayerId player, const float x, const float y) :
    position(x, y), player(player)
{}

Rectangle Paddle::GetBoundingBox()
{
    return {position.x, position.y, size.x, size.y};
}

void Paddle::Update()
{
    const float speedTime{speed * GetFrameTime()};

    if (input::IsMoveUp(player)) position.y -= speedTime;
    if (input::IsMoveDown(player)) position.y += speedTime;

    // Clamp to screen
    if (position.y < 0) position.y = 0;
    if (position.y > static_cast<float>(GetScreenHeight()) - size.y) position.y = static_cast<float>(GetScreenHeight()) - size.y;
}

void Paddle::Draw()
{
    DrawRectangleV(position, size, WHITE);
}
