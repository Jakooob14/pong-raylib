#include "ball.h"

#include <cstdio>

Rectangle Ball::GetBoundingBox()
{
    return { position.x - radius, position.y - radius, radius * 2, radius * 2 };
}

void Ball::Update()
{
    position.x += velocity.x * GetFrameTime();
    position.y += velocity.y * GetFrameTime();

    if (position.y < 0 || position.y > static_cast<float>(GetScreenHeight()) - radius)
    {
        velocity.y *= -1;
    }

    if (position.x < 0 || position.x > static_cast<float>(GetScreenWidth()) - radius)
    {
        printf("Death\n");
    }
}

void Ball::Draw()
{
    DrawCircleV(position, radius, WHITE);
}
