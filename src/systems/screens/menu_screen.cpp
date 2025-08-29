#include "menu_screen.h"

#include "game_screen.h"
#include "../../components/ui/button.h"
#include "../../core/game.h"

void MenuScreen::Update()
{
    Screen::Update();
}

void MenuScreen::Draw()
{
    Screen::Draw();
}

void MenuScreen::Initialize()
{
    Screen::Initialize();

    AddButton("Play", [this](){ PlayClick(); });
    AddButton("Hi!!!");
}

void MenuScreen::AddButton(const char* text, const std::function<void()>& onClick)
{
    auto* button = AddComponent<Button>();

    constexpr Vector2 size{250.0f, 40.0f};
    const Vector2 pos{
        static_cast<float>(GetScreenWidth()) / 2.0f - size.x / 2.0f,
        static_cast<float>(GetScreenHeight()) / 2.0f - size.y / 2.0f + static_cast<float>(buttons) * size.y
    };

    button->SetPosition(pos);
    button->SetSize(size);
    button->SetText(text);
    if (onClick) button->SetOnClick(onClick);

    ++buttons;
}

void MenuScreen::PlayClick() {
    game.SetCurrentScreen(std::make_unique<GameScreen>(game));
}
