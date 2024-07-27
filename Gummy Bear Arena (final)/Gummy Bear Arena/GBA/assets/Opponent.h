#ifndef Opponent_H
#define Opponent_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Character.h"

using namespace std;


class Opponent : public Character {
public:
    Opponent(const string& name, int health, int attack, int defense, int speed)
        : Character(name, health, attack, defense, speed) {}

    ~Opponent() {}
    void attackOpponent(Character& opponent) override {
        // Implement attack logic
        int damage = attack - opponent.getDefense();
        opponent.setHealth(opponent.getHealth() - damage);
        cout << getName() << " attacks " << opponent.getName() << " for " << damage << " damage!" << endl;
    }

    void defend() override {
        // Implement defend logic
        defense += 2;
        cout << name << " defends, increasing defense!" << endl;
    }
};

#endif