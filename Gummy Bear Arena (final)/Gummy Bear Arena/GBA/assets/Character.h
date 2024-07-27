#ifndef Character_H
#define Character_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character {
protected:
    string name;
    int health;
    int attack;
    int defense;
    int speed;

public:
    Character(const string& name, int health, int attack, int defense, int speed)
        : name(name), health(health), attack(attack), defense(defense), speed(speed) {}
    
    ~Character() {}
    virtual string getName() const { return name; }
    virtual int getHealth() { return health; }
    virtual int getAttack() { return attack; }
    virtual int getDefense() { return defense; }
    virtual int getSpeed() { return speed; }
    virtual void setHealth(int newHealth) { health = newHealth; }
    virtual void setAttack(int newAttack) { attack = newAttack; }
    virtual void setDefense(int newDefense) { defense = newDefense; }
    virtual void setSpeed(int newSpeed) { speed = newSpeed; }

    virtual void attackOpponent(Character& opponent) = 0;

    virtual void defend() = 0;

    virtual void displayStats() const {
        cout << "Name: " << name << endl; 
        cout << "Health: " << health << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Speed: " << speed << endl;
    }
};

#endif