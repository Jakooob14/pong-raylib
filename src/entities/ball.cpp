#include "ball.h"

#include <cstdio>

#include "../core/types/player_id.h"

Rectangle Ball::GetBoundingBox()
{
    return { position.x - radius, position.y - radius, radius * 2, radius * 2 };
}

void Ball::Update()
{
    position.x += velocity.x * GetFrameTime();
    position.y += velocity.y * GetFrameTime();

    if (position.y < radius || position.y > static_cast<float>(GetScreenHeight()) - radius)
    {
        velocity.y *= -1;
    }

    if (position.x > static_cast<float>(GetScreenWidth()) - radius)
    {
        if (onLose) onLose(PlayerId::PLAYER_RIGHT);
        Destroy();
    }

    if (position.x < radius)
    {
        if (onLose) onLose(PlayerId::PLAYER_LEFT);
        Destroy();
    }
}

void Ball::Draw()
{
    DrawCircleV(position, radius, WHITE);
}
