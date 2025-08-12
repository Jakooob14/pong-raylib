#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H
#include "screen.h"


class MenuScreen : public Screen
{
protected:
    void Update() override;
    void Draw() override;
};



#endif //MENU_SCREEN_H
