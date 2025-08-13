#include "ui_component.h"

#include "raylib.h"
#include "../../core/globals.h"
#include "../../utils/input.h"

void UIComponent::Update()
{
    // Make sure it sends event only once with `clicked` bool
    if (input::IsConfirming() && IsHovering() && !hasClicked)
    {
        hasClicked = true;
        if (onClick) onClick();
    }

    // Reset click
    if (hasClicked && !input::IsConfirming()) hasClicked = false;
}

bool UIComponent::IsHovering() const
{
    const Vector2 mousePos{GetMousePosition()};

    if (mousePos.x < position.x) return false;
    if (mousePos.x > size.x + position.x) return false;

    if (mousePos.y < position.y) return false;
    if (mousePos.y > size.y + position.y) return false;

    return true;
}
