#include "ui_component.h"

#include "raylib.h"
#include "../../core/globals.h"
#include "../../utils/input.h"

void UIComponent::Update()
{
    position = CalculateAnchoredPosition();

    // Make sure it sends event only once with `clicked` bool
    if (input::IsConfirming() && IsHovering() && !hasClicked)
    {
        hasClicked = true;
        if (onClick) onClick();
    }

    // Reset click
    if (hasClicked && !input::IsConfirming()) hasClicked = false;
}

Vector2 UIComponent::CalculateAnchoredPosition()
{
    const Vector2 windowSize{
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())
    };

    Vector2 anchoredPosition{};

    switch (anchor) {
        case Anchor::TOP_RIGHT:
            anchoredPosition.x = windowSize.x - size.x + basePosition.x;
            anchoredPosition.y = basePosition.y;
            break;
        case Anchor::TOP_CENTER:
            anchoredPosition.x = windowSize.x / 2.0f - size.x / 2.0f + basePosition.x;
            anchoredPosition.y = basePosition.y;
            break;
        case Anchor::BOTTOM_LEFT:
            anchoredPosition.x = basePosition.x;
            anchoredPosition.y = windowSize.y - size.y + basePosition.y;
            break;
        case Anchor::BOTTOM_CENTER:
            anchoredPosition.x = windowSize.x / 2.0f - size.x / 2.0f + basePosition.x;
            anchoredPosition.y = windowSize.y - size.y + basePosition.y;
            break;
        case Anchor::BOTTOM_RIGHT:
            anchoredPosition.x = windowSize.x - size.x + basePosition.x;
            anchoredPosition.y = windowSize.y - size.y + basePosition.y;
            break;
        case Anchor::CENTER_LEFT:
            anchoredPosition.x = basePosition.x;
            anchoredPosition.y = windowSize.y / 2.0f - size.y / 2.0f + basePosition.y;
            break;
        case Anchor::CENTER_RIGHT:
            anchoredPosition.x = windowSize.x - size.x + basePosition.x;
            anchoredPosition.y = windowSize.y / 2.0f - size.y / 2.0f + basePosition.y;
            break;
        case Anchor::CENTER:
            anchoredPosition.x = windowSize.x / 2.0f - size.x / 2.0f + basePosition.x;
            anchoredPosition.y = windowSize.y / 2.0f - size.y / 2.0f + basePosition.y;
            break;
        default:
            return basePosition;
    }

    return anchoredPosition;
}

void UIComponent::SetPosition(const Vector2& value)
{
    position = value;
    basePosition = value;
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
