#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H
#include <functional>

#include "raylib.h"
#include "../../core/game_component.h"


class UIComponent : public GameComponent
{
public:
    UIComponent() = default;

    [[nodiscard]] Vector2 GetPosition() const { return position; }
    void SetPosition(const Vector2& value) { position = value; }

    [[nodiscard]] Vector2 GetSize() const { return size; }
    void SetSize(const Vector2& value) { size = value; }

    void SetOnClick(const std::function<void()>& value) { onClick = value; }

    [[nodiscard]] bool IsHovering() const;

protected:
    void Update() override;

private:
    Vector2 position{0.0f, 0.0f};
    Vector2 size{150.0f, 30.0f};
    Color backgroundColor{WHITE};
    Color textColor{BLACK};
    const char* text{};

    bool hasClicked{false};

    std::function<void()> onClick{nullptr};
};



#endif //UI_COMPONENT_H
