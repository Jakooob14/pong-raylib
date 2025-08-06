#ifndef SCREEN_H
#define SCREEN_H
#include <memory>
#include <vector>
#include <raylib.h>

#include "../../core/game_component.h"

class Screen
{
public:
    virtual ~Screen() = default;

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
    T* AddComponent(Args&&... args)
    {
        static_assert(std::is_base_of_v<GameComponent, T>, "T must inherit from GameComponent");

        // Create a smart pointer and forward `args` to it
        auto component = std::make_unique<T>(std::forward<Args>(args)...);

        T* ptr = component.get();

        // Convert derived unique_ptr to base unique_ptr and transfer ownership to components vector
        components.push_back(std::unique_ptr<GameComponent>(static_cast<GameComponent*>(component.release())));

        return ptr;
    }

protected:
    virtual void Update();
    virtual void Draw();
    // Initialize game components and other starting game stuff
    virtual void Initialize() {}

    friend class Game;

private:
    static constexpr Color screenBackgroundColor{BLACK};

    // All on-screen components
    std::vector<std::unique_ptr<GameComponent>> components{};
};



#endif //SCREEN_H
