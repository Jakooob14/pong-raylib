#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>

#include "../entities/paddle.h"


class Ball;

class Game
{
public:
    void Run();

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
    static constexpr int windowWidth{800};
    static constexpr int windowHeight{600};
    static constexpr Color windowBackgroundColor{BLACK};

    // All on-screen components
    std::vector<std::unique_ptr<GameComponent>> components{};


    Paddle* paddleLeft{nullptr};
    Paddle* paddleRight{nullptr};

    Ball* ball{nullptr};

    void UpdateAll();
    void DrawAll();
    // Initialize game components and other starting game stuff
    void Initialize();
};


#endif //GAME_H
