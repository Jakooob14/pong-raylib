#include "text.h"

#include "../../core/globals.h"
#include "../../systems/screens/screen.h"

void Text::Draw()
{
    const float actualFontSize{static_cast<float>(font.baseSize) * fontSize};
    SetSize(MeasureTextEx(font, text, actualFontSize, spacing));
    DrawTextEx(font, text, GetPosition(), actualFontSize, spacing, textColor);
}