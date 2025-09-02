#ifndef TEXT_H
#define TEXT_H
#include "ui_component.h"
#include "../../core/globals.h"


class Text : public UIComponent
{
public:
    explicit Text(const char* text) : text(text) {}

    [[nodiscard]] Color GetTextColor() const { return textColor; }
    void SetTextColor(const Color& value) { textColor = value; }

    [[nodiscard]] const char *GetText() const { return text; }
    void SetText(const char* value) { text = value; }

    [[nodiscard]] float GetFontSize() const { return fontSize; }
    void SetFontSize(const float& value) { fontSize = value; }

    [[nodiscard]] float GetSpacing() const { return spacing; }
    void SetSpacing(const float& value) { spacing = value; }

    [[nodiscard]] Font GetFont() const { return font; }
    void SetFont(const Font& value) { font = value; }

protected:
    void Draw() override;

private:
    Color textColor{WHITE};
    const char* text{};
    float fontSize{3.0f};
    float spacing{4.0f};
    Font font{mechaFont};
};



#endif //TEXT_H
