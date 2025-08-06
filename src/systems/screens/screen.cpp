#include "screen.h"
#include "../../core/game_component.h"

#include <raylib.h>


void Screen::Update()
{
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
