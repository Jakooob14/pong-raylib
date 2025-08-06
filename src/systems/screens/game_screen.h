#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include "screen.h"


class Ball;
class Paddle;

class GameScreen : public Screen
{
protected:
    void Update() override;
    void Initialize() override;

private:
    Paddle* paddleLeft{nullptr};
    Paddle* paddleRight{nullptr};

    Ball* ball{nullptr};
};



#endif //GAME_SCREEN_H
