#ifndef GummyBear_H
#define GummyBear_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "GummyBear.h"

using namespace std;

class GummyBear : public Character {
public:
    GummyBear(const string& name, int health, int attack, int defense, int speed)
        : Character(name, health, attack, defense, speed) {}
        
    ~GummyBear() {}
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