#include "game.h"
#include <raylib.h>

#include "../entities/ball.h"
#include "types/player_id.h"

void Game::Run()
{
    InitWindow(windowWidth, windowHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    Initialize();

    while (!WindowShouldClose())
    {
        UpdateAll();
        DrawAll();
    }

    CloseWindow();
}

template<typename T, typename ...Args>
T* Game::AddComponent(Args&&... args)
{
    static_assert(std::is_base_of_v<GameComponent, T>, "T must inherit from GameComponent");

    // Create a smart pointer and forward `args` to it
    auto component = std::make_unique<T>(std::forward<Args>(args)...);

    T* ptr = component.get();

    // Convert derived unique_ptr to base unique_ptr and transfer ownership to components vector
    components.push_back(std::unique_ptr<GameComponent>(static_cast<GameComponent*>(component.release())));

    return ptr;
}

void Game::UpdateAll()
{
    for (auto &component : components) {
        component->Update();
    }

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

void Game::DrawAll()
{
    BeginDrawing();

    ClearBackground(windowBackgroundColor);

    for (auto& component : components) {
        component->Draw();
    }

    EndDrawing();
}

void Game::Initialize()
{
    // Create paddles 100px from borders at the top of screen
    paddleLeft = AddComponent<Paddle>(PlayerId::PLAYER_LEFT, 100.0f, 0.0f);
    paddleRight = AddComponent<Paddle>(PlayerId::PLAYER_RIGHT, static_cast<float>(GetScreenWidth()) - 100.0f, 0.0f);

    ball = AddComponent<Ball>();
}
