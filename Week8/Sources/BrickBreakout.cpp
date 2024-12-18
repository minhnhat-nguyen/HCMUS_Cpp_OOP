#include "BrickBreakout.h"
#include <iostream>

Ball* Ball::instance = nullptr;

Ball::Ball() {
    x = 0;
    y = 0;
}

Ball* Ball::getInstance() {
    if (instance == nullptr) {
        instance = new Ball();
    }
    return instance;
}

Ball* Ball::getNewInstance() {
    Ball* t = instance;
    instance = new Ball();
    delete t;
    return instance;
}

void Ball::clearInstance() {
    delete instance;
    instance = nullptr;
}

Brick::Brick() { isBroken = false; }

Game::Game() {
    bar = new Bar();
    ball = Ball::getInstance();
}

Game::~Game() {
    delete bar;
    delete ball;
    for (auto brick : bricks) {
        delete brick;
    }
}

void Game::startOver() {
    delete bar;
    bar = new Bar();
    ball = Ball::getNewInstance();
}

void Game::addBrick(Brick* brick) { bricks.push_back(brick); }