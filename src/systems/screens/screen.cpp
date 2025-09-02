#include "screen.h"

#include <algorithm>

#include "../../core/game_component.h"

#include <raylib.h>


void Screen::Update()
{
    // Remove components marked for destruction
    std::erase_if(components,
                  [](const std::unique_ptr<GameComponent>& component) { return component->IsDestroyed(); });

    for (auto &component : components) {
        if (!component) continue;
        component->Update();
    }
}

void Screen::Draw()
{
    ClearBackground(screenBackgroundColor);

    for (auto& component : components) {
        if (!component) continue;
        component->Draw();
    }
}
