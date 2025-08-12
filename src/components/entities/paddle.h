#ifndef PADDLE_H
#define PADDLE_H
#include "raylib.h"
#include "../core/game_component.h"

enum class PlayerId;

class Paddle : public GameComponent
{
public:
    explicit Paddle(PlayerId player, float x, float y);
    Rectangle GetBoundingBox();

protected:
    void Update() override;
    void Draw() override;

private:
    float x{};
    float y{};

    float speed{300.0f};

    int width{10};
    int height{60};

    PlayerId player{};
};


#endif //PADDLE_H
