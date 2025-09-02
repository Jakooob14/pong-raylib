#include "menu_screen.h"

#include "game_screen.h"
#include "../../components/ui/button.h"
#include "../../components/ui/text.h"
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
    AddButton("Exit", [this](){ game.Exit(); });

    auto* text = AddComponent<Text>("Pong");
    text->SetAnchor(UIComponent::Anchor::CENTER);
    text->SetFontSize(10.0f);
    text->SetPosition(Vector2{0.0f, -120.0f});
}

Button* MenuScreen::AddButton(const char* text, const std::function<void()>& onClick)
{
    auto* button = AddComponent<Button>();

    constexpr Vector2 size{250.0f, 40.0f};
    const Vector2 pos = {0.0f, static_cast<float>(buttons) * size.y};

    button->SetAnchor(UIComponent::Anchor::CENTER);
    button->SetPosition(pos);
    button->SetSize(size);
    button->SetText(text);
    if (onClick) button->SetOnClick(onClick);

    ++buttons;

    return button;
}

void MenuScreen::PlayClick() {
    game.SetCurrentScreen(std::make_unique<GameScreen>(game));
}
