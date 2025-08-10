#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include "screen.h"
#include "../../utils/timers/function_timer.h"


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

    std::shared_ptr<FunctionTimer> spawnTimer{std::make_shared<FunctionTimer>(2.9f, [this](){ SpawnBall(); })};

    void Lost(PlayerId player);
    void SpawnBall();
    void DrawScore();
    void DrawSpawnTimer() const;
};



#endif //GAME_SCREEN_H
