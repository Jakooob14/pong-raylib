#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H



class GameComponent
{
public:
    virtual ~GameComponent() = default;

    [[nodiscard]] bool IsDestroyed() const { return destroyed; }
    void Destroy() { destroyed = true; }

protected:
    virtual void Update() = 0;
    virtual void Draw() = 0;

    friend class Screen;

private:
    bool destroyed{false};
};



#endif //GAMECOMPONENT_H
