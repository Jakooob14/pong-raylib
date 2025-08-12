#include "ball.h"

#include <cstdio>

#include "../core/types/player_id.h"

Rectangle Ball::GetBoundingBox()
{
    return {position.x, position.y, size.x, size.y};
}

void Ball::Update()
{
    position.x += velocity.x * GetFrameTime();
    position.y += velocity.y * GetFrameTime();

    if (position.y < size.y || position.y > static_cast<float>(GetScreenHeight()) - size.y)
    {
        velocity.y *= -1;
    }

    if (position.x > static_cast<float>(GetScreenWidth()) - size.x)
    {
        if (onLose) onLose(PlayerId::PLAYER_RIGHT);
        Destroy();
    }

    if (position.x < size.x)
    {
        if (onLose) onLose(PlayerId::PLAYER_LEFT);
        Destroy();
    }
}

void Ball::Draw()
{
    DrawRectangleV(position, size, WHITE);
}
