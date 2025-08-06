#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H



class GameComponent
{
public:
    virtual ~GameComponent() = default;

protected:
    virtual void Update() = 0;
    virtual void Draw() = 0;

    friend class Game;
    friend class Screen;
};



#endif //GAMECOMPONENT_H
