#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H



class GameComponent
{
public:
    virtual ~GameComponent() = default;

    void Destroy() { destroyed = true; }
    bool IsDestroyed() const { return destroyed; }

protected:
    virtual void Update() = 0;
    virtual void Draw() = 0;

    friend class Screen;

private:
    bool destroyed{false};
};



#endif //GAMECOMPONENT_H
