#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include "screen.h"


enum class PlayerId;
class Ball;
class Paddle;

class GameScreen : public Screen
{
protected:
    void Update() override;
    void Draw() override;
    void Initialize() override;

private:
    Paddle* paddleLeft{nullptr};
    Paddle* paddleRight{nullptr};

    Ball* ball{nullptr};

    int scorePlayerLeft{0};
    int scorePlayerRight{0};

    void Lost(PlayerId player);
};



#endif //GAME_SCREEN_H
