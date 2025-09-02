#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H
#include <functional>

#include "screen.h"


class Button;

class MenuScreen : public Screen
{
public:
    explicit MenuScreen(Game& game) : Screen(game) {}

protected:
    void Update() override;
    void Draw() override;
    void Initialize() override;

private:
    int buttons{0};

    Button* AddButton(const char* text, const std::function<void()>& onClick = nullptr);
    void PlayClick();
};



#endif //MENU_SCREEN_H
