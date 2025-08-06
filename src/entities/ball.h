#ifndef BALL_H
#define BALL_H
#include "raylib.h"
#include "../core/game_component.h"


class Ball : public GameComponent
{
public:
    Rectangle GetBoundingBox();

    float radius{10.0f};

    // Spawn in middle of screen
    Vector2 position{
        static_cast<float>(GetScreenWidth())/2 - radius/2,
        static_cast<float>(GetScreenHeight())/2 - radius/2
    };

    Vector2 velocity{200.0f, -150.0f};

protected:
    void Update() override;
    void Draw() override;
};



#endif //BALL_H
