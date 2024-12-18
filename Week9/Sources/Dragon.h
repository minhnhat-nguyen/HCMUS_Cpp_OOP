#pragma once
#include <iostream>

class Dragon;

class State {
   public:
    virtual double getAtkDamage(Dragon* d) const = 0;
    virtual void attack(Dragon* d) const = 0;
    virtual void move(Dragon* d) const = 0;
};

class NormalState : public State {
   public:
    NormalState() = default;
    double getAtkDamage(Dragon* d) const;
    void attack(Dragon* d) const;
    void move(Dragon* d) const;
};

class RampageState : public State {
   public:
    RampageState() = default;
    double getAtkDamage(Dragon* d) const;
    void attack(Dragon* d) const;
    void move(Dragon* d) const;
};

class DefenseState : public State {
   public:
    DefenseState() = default;
    double getAtkDamage(Dragon* d) const;
    void attack(Dragon* d) const;
    void move(Dragon* d) const;
};

class Dragon {
    friend NormalState;
    friend RampageState;
    friend DefenseState;

   private:
    std::string name;
    long _level;
    double _atk;
    double _def;
    double _hp;
    const State* _state;

   public:
    Dragon(std::string name, long level, double atk, double def, double hp);
    void setState(const State& state);
    void attack();
    void move();
    double getAtkDamage();
    const static NormalState NORMAL_STATE;
    const static RampageState RAMPAGE_STATE;
    const static DefenseState DEFENSE_STATE;
};
