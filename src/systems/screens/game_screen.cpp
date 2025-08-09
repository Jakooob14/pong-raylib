#include "game_screen.h"

#include <cstdio>
#include <format>
#include <random>

#include "../../core/globals.h"
#include "../../entities/ball.h"
#include "../../entities/paddle.h"
#include "../../core/types/player_id.h"
#include "../../utils/random.h"

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

void GameScreen::Draw()
{
    Screen::Draw();

    const float fontSize{static_cast<float>(mechaFont.baseSize) * 3.0f};
    constexpr float spacing{4.0f};
    // TODO: ADD SCORE
    const std::string text{std::format("{} : {}", scorePlayerLeft, scorePlayerRight)};

    const float x{static_cast<float>(GetScreenWidth()) / 2.0f - MeasureTextEx(mechaFont, text.c_str(), fontSize, spacing).x / 2.0f};

    DrawTextEx(mechaFont, text.c_str(), Vector2{x, 0}, fontSize, spacing, WHITE);
}

void GameScreen::Initialize()
{
    Screen::Initialize();

    // Create paddles 100px from borders at the top of screen
    paddleLeft = AddComponent<Paddle>(PlayerId::PLAYER_LEFT, 100.0f, 0.0f);
    paddleRight = AddComponent<Paddle>(PlayerId::PLAYER_RIGHT, static_cast<float>(GetScreenWidth()) - 100.0f, 0.0f);

    ball = AddComponent<Ball>();
    ball->onLose = [this](PlayerId player){ Lost(player); };
}

void GameScreen::Lost(PlayerId player)
{
    if (player == PlayerId::PLAYER_LEFT)
    {
        ++scorePlayerRight;
    } else
    {
        ++scorePlayerLeft;
    }

    ball = AddComponent<Ball>();
    ball->onLose = [this](PlayerId player){ Lost(player); };
}
