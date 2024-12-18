#pragma once
#include <vector>

class Bar {
   public:
    Bar() = default;
    ~Bar() = default;
};

class Ball {
   private:
    int x, y;
    static Ball* instance;
    Ball();

   public:
    static Ball* getInstance();
    static Ball* getNewInstance();
    static void clearInstance();
    //clear instance
    int getX() { return x; }
    int getY() { return y; }
    void setX(int _x) { x = _x; }
    void setY(int _y) { y = _y; }
};

class Brick {
    bool isBroken;
   public:
    Brick();
    ~Brick() = default;
};

class Game {
    std::vector<Brick*> bricks;
    Bar* bar;
    Ball* ball;

   public:
    Game();
    ~Game();
    void startOver();
    void addBrick(Brick* brick);
};