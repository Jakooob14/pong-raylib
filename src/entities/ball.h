#ifndef BALL_H
#define BALL_H
#include <functional>

#include "raylib.h"
#include "../core/game_component.h"
#include "../utils/random.h"


enum class PlayerId;

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

    Vector2 velocity{
        250.0f * (GetRandomBool() ? 1.0f : -1.0f),
        static_cast<float>(GetRandomDouble(100, 200, 2)) * (GetRandomBool() ? 1.0f : -1.0f)
    };

    // Callback for death event
    std::function<void(PlayerId player)> onLose{nullptr};

protected:
    void Update() override;
    void Draw() override;
};



#endif //BALL_H
