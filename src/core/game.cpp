#include "game.h"
#include <raylib.h>

#include "globals.h"
#include "../systems/screens/game_screen.h"
#include "../systems/screens/screen.h"

void Game::Run()
{
    InitWindow(windowWidth, windowHeight, "My first RAYLIB program!");
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
    if (!currentScreen) return;
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
    auto* gameScreen = new GameScreen();
    SetCurrentScreen(gameScreen);
}
