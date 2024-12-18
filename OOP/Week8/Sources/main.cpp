#include "Circuit.h"
#include <iostream>
#include "BrickBreakout.h"
int main() {
    //bai1
    Ball* b = Ball::getInstance();
    b->setX(10);
    b->setY(20);
    std::cout << b->getX() << " " << b->getY() << std::endl;
    b = Ball::getNewInstance();
    std::cout << b->getX() << " " << b->getY() << std::endl;
    b->clearInstance();
    std::vector<Circuit*> circuits;
    resistor r1(10, 1);
    resistor r2(20, 2);
    resistor r3(30, 3);
    SingleCircuit c1(r1), c2(r2), c3(r3);
    circuits.push_back(&c1);
    circuits.push_back(&c2);
    circuits.push_back(&c3);
    SerialCircuit serialCircuit(circuits);
    std::cout << "Serial circuit resistance: " << serialCircuit.getResistance() << std::endl;
    ParallelCircuit parallelCircuit(circuits);
    std::cout << "Parallel circuit resistance: " << parallelCircuit.getResistance() << std::endl;
    parallelCircuit.addCircuit(&serialCircuit);
    std::cout << "Parallel circuit resistance: " << parallelCircuit.getResistance() << std::endl;

}