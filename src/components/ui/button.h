#ifndef BUTTON_H
#define BUTTON_H
#include "raylib.h"
#include "ui_component.h"


class UIButton : public  UIComponent
{
public:
    UIButton() {}
    UIButton(const Vector2 position, const Vector2 size) :
        position(position), size(size)
    {}

    Vector2 GetPosition() const { return position; }
    void SetPosition(const Vector2 value) { position = value; }
    Vector2 GetSize() const { return size; }
    void SetSize(const Vector2 value) { size = value; }
    Color GetBackgroundColor() const { return backgroundColor; }
    void SetBackgroundColor(const Color value) { backgroundColor = value; }

protected:
    void Update() override;
    void Draw() override;

private:
    Vector2 position{0.0f, 0.0f};
    Vector2 size{10.0f, 30.0f};
    Color backgroundColor{WHITE};
};



#endif //BUTTON_H
