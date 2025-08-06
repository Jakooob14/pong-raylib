#include "game_screen.h"
#include "../../entities/ball.h"
#include "../../entities/paddle.h"
#include "../../core/types/player_id.h"

void GameScreen::Update()
{
    Screen::Update();

    if (CheckCollisionCircleRec(ball->position, ball->radius, paddleLeft->GetBoundingBox()))
    {
        // If already in the direction return
        if (ball->velocity.x > 0.0f) return;
        ball->velocity.x *= -1;
    }

    if (CheckCollisionCircleRec(ball->position, ball->radius, paddleRight->GetBoundingBox()))
    {
        // If already in the direction return
        if (ball->velocity.x < 0.0f) return;
        ball->velocity.x *= -1;
    }
}

void GameScreen::Initialize()
{
    Screen::Initialize();

    // Create paddles 100px from borders at the top of screen
    paddleLeft = AddComponent<Paddle>(PlayerId::PLAYER_LEFT, 100.0f, 0.0f);
    paddleRight = AddComponent<Paddle>(PlayerId::PLAYER_RIGHT, static_cast<float>(GetScreenWidth()) - 100.0f, 0.0f);

    ball = AddComponent<Ball>();
}
