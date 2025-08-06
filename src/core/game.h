#ifndef GAME_H
#define GAME_H
#include <memory>
#include <raylib.h>


class Screen;
class Ball;

class Game
{
public:
    // ~Game();

    void Run();

    void SetCurrentScreen(Screen* screen);

private:
    static constexpr int windowWidth{800};
    static constexpr int windowHeight{600};
    static constexpr Color windowBackgroundColor{BLACK};

    Screen* currentScreen{nullptr};

    void Update();
    void Draw();
    // Initialize game components and other starting game stuff
    void Initialize();
};


#endif //GAME_H
