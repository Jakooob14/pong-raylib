#ifndef GAME_H
#define GAME_H
#include <memory>
#include <random>
#include <raylib.h>

#include "../systems/screens/screen.h"


class Ball;

class Game
{
public:
    void Run();

    void SetCurrentScreen(std::unique_ptr<Screen> screen);

private:
    static constexpr int windowWidth{800};
    static constexpr int windowHeight{600};
    static constexpr Color windowBackgroundColor{BLACK};

    std::unique_ptr<Screen> currentScreen{nullptr};


    void Update();
    void Draw();
    // Initialize game components and other starting game stuff
    void Initialize();
};


#endif //GAME_H
