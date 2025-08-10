#include "game_screen.h"

#include <format>

#include "../../core/globals.h"
#include "../../entities/ball.h"
#include "../../entities/paddle.h"
#include "../../core/types/player_id.h"

void GameScreen::Update()
{
    Screen::Update();

    if (ball && paddleLeft && paddleRight)
    {
        if (CheckCollisionRecs(ball->GetBoundingBox(), paddleLeft->GetBoundingBox()))
        {
            // If already in the direction return
            if (ball->velocity.x > 0.0f) return;
            ball->velocity.x *= -1;
        }

        if (CheckCollisionRecs(ball->GetBoundingBox(), paddleRight->GetBoundingBox()))
        {
            // If already in the direction return
            if (ball->velocity.x < 0.0f) return;
            ball->velocity.x *= -1;
        }
    }
}

void GameScreen::Draw()
{
    Screen::Draw();

    DrawScore();
    DrawSpawnTimer();
}

void GameScreen::Initialize()
{
    Screen::Initialize();

    // Create paddles 100px from borders at the top of screen
    paddleLeft = AddComponent<Paddle>(PlayerId::PLAYER_LEFT, 100.0f, 0.0f);
    paddleRight = AddComponent<Paddle>(PlayerId::PLAYER_RIGHT, static_cast<float>(GetScreenWidth()) - 100.0f, 0.0f);

    timerManager.StartTimedFunction(spawnTimer);
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

    spawnTimer->Reset();
    timerManager.StartTimedFunction(spawnTimer);
}

void GameScreen::SpawnBall()
{
    ball = AddComponent<Ball>();
    ball->onLose = [this](const PlayerId player){ Lost(player); };
}

void GameScreen::DrawScore()
{
    const float fontSize{static_cast<float>(mechaFont.baseSize) * 3.0f};
    constexpr float spacing{4.0f};
    const std::string text{std::format("{} : {}", scorePlayerLeft, scorePlayerRight)};

    const float x{static_cast<float>(GetScreenWidth()) / 2.0f - MeasureTextEx(mechaFont, text.c_str(), fontSize, spacing).x / 2.0f};

    DrawTextEx(mechaFont, text.c_str(), Vector2{x, 0}, fontSize, spacing, WHITE);
}

void GameScreen::DrawSpawnTimer() const
{
    if (spawnTimer->IsDone()) return;

    const float fontSize{static_cast<float>(mechaFont.baseSize) * 9.0f};
    constexpr float spacing{4.0f};
    const float time{fmaxf(floorf(spawnTimer->GetTtl() - spawnTimer->GetElapsed() + 1.0f), 1.0f)};
    const std::string text{std::format("{}", time)};

    const float x{static_cast<float>(GetScreenWidth()) / 2.0f - MeasureTextEx(mechaFont, text.c_str(), fontSize, spacing).x / 2.0f};
    const float y{static_cast<float>(GetScreenHeight()) / 2.0f - MeasureTextEx(mechaFont, text.c_str(), fontSize, spacing).y / 2.0f};

    DrawTextEx(mechaFont, text.c_str(), Vector2{x, y}, fontSize, spacing, WHITE);
}
