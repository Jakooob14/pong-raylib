#ifndef PADDLE_H
#define PADDLE_H
#include "raylib.h"
#include "../../core/game_component.h"

enum class PlayerId;

class Paddle : public GameComponent
{
public:
    explicit Paddle(PlayerId player, float x, float y);

    [[nodiscard]] Rectangle GetBoundingBox();

    [[nodiscard]] Vector2 GetPosition() const { return position; }
    void SetPosition(const Vector2& value) { position = value; }

    [[nodiscard]] Vector2 GetSize() const { return size; }
    void SetSize(const Vector2& value) { size = value; }

protected:
    void Update() override;
    void Draw() override;

private:
    Vector2 position{};
    Vector2 size{10, 60};

    float speed{300.0f};

    PlayerId player{};
};


#endif //PADDLE_H
