#ifndef SCREEN_H
#define SCREEN_H
#include <memory>
#include <vector>

#include "raylib.h"


class GameComponent;

class Screen
{
public:
    /**
     * @brief Adds a new component of type T to the game.
     *
     * Creates and adds a component of type T to the `components` vector,
     * forwarding the provided arguments to T's constructor.
     *
     * @tparam T The type of the component to add. Must derive from GameComponent.
     * @tparam Args Argument types for T's constructor.
     * @param args Arguments to forward to T's constructor.
     * @return T* Pointer to the newly added component.
     */
    template<typename T, typename ...Args>
    T* AddComponent(Args&&... args);

private:
    static constexpr Color screenBackgroundColor{BLACK};

    // All on-screen components
    std::vector<std::unique_ptr<GameComponent>> components{};

    void UpdateAll();
    void DrawAll();
    // Initialize game components and other starting game stuff
    void Initialize();
};



#endif //SCREEN_H
