#include "game.h"

#include <cassert>
#include <raylib.h>

#include "globals.h"
#include "../systems/screens/game_screen.h"
#include "../systems/screens/menu_screen.h"
#include "../systems/screens/screen.h"

void Game::Run()
{
    InitWindow(windowWidth, windowHeight, "Pong");
    SetTargetFPS(60);

    Initialize();

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    CloseWindow();
}

void Game::SetCurrentScreen(Screen *screen)
{
    currentScreen = screen;
    currentScreen->Initialize();
}

void Game::Update()
{
    const float deltaTime{GetFrameTime()};

    timerManager.UpdateTimers(deltaTime);

    assert(currentScreen && "currentScreen is null in Game::Update()");
    currentScreen->Update();
}

void Game::Draw()
{
    BeginDrawing();

    ClearBackground(windowBackgroundColor);

    if (currentScreen) currentScreen->Draw();

    EndDrawing();
}

void Game::Initialize()
{
    // Load global assets
    mechaFont = LoadFont("../resources/fonts/mecha.png");

    // Create and set current screen
    SetCurrentScreen(new MenuScreen());
}
