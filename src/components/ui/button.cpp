#include "button.h"

#include "raylib.h"
#include "../../core/globals.h"
#include "../../utils/input.h"

void Button::Draw()
{
    const Vector2 position{GetPosition()};
    const Vector2 size{GetSize()};

    DrawRectangleV(position, size, IsHovering() ? backgroundColor : textColor);

    const float fontSize{static_cast<float>(mechaFont.baseSize) * 3.0f};
    constexpr float spacing{4.0f};

    const Vector2 textPos{
        size.x / 2.0f - MeasureTextEx(mechaFont, text, fontSize, spacing).x / 2.0f + position.x,
        size.y / 2.0f - MeasureTextEx(mechaFont, text, fontSize, spacing).y / 2.0f + position.y
    };

    DrawTextEx(mechaFont, text, textPos, fontSize, spacing, IsHovering() ? textColor : backgroundColor);
}