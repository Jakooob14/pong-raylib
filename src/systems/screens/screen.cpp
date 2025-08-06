#include "screen.h"

#include "raylib.h"

template<typename T, typename ...Args>
T* Screen::AddComponent(Args&&... args)
{
    static_assert(std::is_base_of_v<GameComponent, T>, "T must inherit from GameComponent");

    // Create a smart pointer and forward `args` to it
    auto component = std::make_unique<T>(std::forward<Args>(args)...);

    T* ptr = component.get();

    // Convert derived unique_ptr to base unique_ptr and transfer ownership to components vector
    components.push_back(std::unique_ptr<GameComponent>(static_cast<GameComponent*>(component.release())));

    return ptr;
}

void Screen::UpdateAll()
{
    for (auto &component : components) {
        component->Update();
    }
}

void Screen::DrawAll()
{
    ClearBackground(screenBackgroundColor);

    for (auto& component : components) {
        component->Draw();
    }
}

void Screen::Initialize()
{
    // Create paddles 100px from borders at the top of screen
    paddleLeft = AddComponent<Paddle>(PlayerId::PLAYER_LEFT, 100.0f, 0.0f);
    paddleRight = AddComponent<Paddle>(PlayerId::PLAYER_RIGHT, static_cast<float>(GetScreenWidth()) - 100.0f, 0.0f);

    ball = AddComponent<Ball>();
}
