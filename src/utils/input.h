#ifndef INPUT_H
#define INPUT_H


enum class PlayerId;

namespace input
{
    bool IsMoveUp(PlayerId player);
    bool IsMoveDown(PlayerId player);
    bool IsConfirming();
}



#endif //INPUT_H
