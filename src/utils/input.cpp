#include "input.h"
#include <raylib.h>
#include "../core/types/player_id.h"

namespace input
{
    bool IsMoveUp(PlayerId player)
    {
        return player == PlayerId::PLAYER_LEFT ? IsKeyDown(KEY_W) : IsKeyDown(KEY_UP);
    }

    bool IsMoveDown(PlayerId player)
    {
        return player == PlayerId::PLAYER_LEFT ? IsKeyDown(KEY_S) : IsKeyDown(KEY_DOWN);
    }
}
