#include "Dragon.h"

#include <iostream>

double NormalState::getAtkDamage(Dragon* d) const {
    return (d->_atk + d->_def + d->_hp) * d->_level;
}

void NormalState::attack(Dragon* d) const {
    std::cout << "Rồng " << d->name << " phun lửa màu vàng\n";
}

void NormalState::move(Dragon* d) const {
    std::cout << "Rồng " << d->name << " di chuyển tốc độ bình thường\n";
}

double RampageState::getAtkDamage(Dragon* d) const {
    return (2 * d->_atk + d->_def + d->_hp) * d->_level;
}

void RampageState::attack(Dragon* d) const {
    std::cout << "Rồng " << d->name << " phun lửa màu đỏ\n";
}

void RampageState::move(Dragon* d) const {
    std::cout << "Rồng " << d->name << " di chuyển nhanh\n";
}

double DefenseState::getAtkDamage(Dragon* d) const {
    return (d->_atk + 1.5 * d->_def + 1.5 * d->_hp) * d->_level;
}

void DefenseState::attack(Dragon* d) const {
    std::cout << "Rồng " << d->name << " phun lửa màu xanh lá\n";
}

void DefenseState::move(Dragon* d) const {
    std::cout << "Rồng " << d->name << " di chuyển chậm\n";
}

Dragon::Dragon(std::string name, long level, double atk, double def, double hp)
    : name(name),
      _level(level),
      _atk(atk),
      _def(def),
      _hp(hp),
      _state(&NORMAL_STATE) {}

void Dragon::setState(const State& state) { _state = &state; }

void Dragon::attack() { _state->attack(this); }

void Dragon::move() { _state->move(this); }

double Dragon::getAtkDamage() { return _state->getAtkDamage(this); }

const NormalState Dragon::NORMAL_STATE = NormalState();
const RampageState Dragon::RAMPAGE_STATE = RampageState();
const DefenseState Dragon::DEFENSE_STATE = DefenseState();