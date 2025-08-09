#include "screen.h"

#include <algorithm>

#include "../../core/game_component.h"

#include <raylib.h>


void Screen::Update()
{
    // Remove components marked for destruction
    components.erase(
        std::remove_if(components.begin(), components.end(),
            [](const std::unique_ptr<GameComponent>& component) { return component->IsDestroyed(); }),
            components.end()
            );

    for (auto &component : components) {
        component->Update();
    }
}

void Screen::Draw()
{
    ClearBackground(screenBackgroundColor);

    for (auto& component : components) {
        component->Draw();
    }
}
