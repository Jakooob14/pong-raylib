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

    // Spawn in middle of screen
    Vector2 position{
        static_cast<float>(GetScreenWidth())/2 - size.x/2,
        static_cast<float>(GetScreenHeight())/2 - size.y/2
    };

    Vector2 size{16.0f, 16.0f};

    Vector2 velocity{
        200.0f * (GetRandomBool() ? 1.0f : -1.0f),
        static_cast<float>(GetRandomDouble(100, 200, 2)) * (GetRandomBool() ? 1.0f : -1.0f)
    };

    // Callback for death event
    std::function<void(PlayerId player)> onLose{nullptr};

protected:
    void Update() override;
    void Draw() override;
};



#endif //BALL_H
