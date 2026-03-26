#include <iostream>
#include <string>
using namespace std;

class Warrior {
public:
    // Basic attack
    void attack() {
        cout << "You strike the rock with a basic attack! *thud*" << endl;
    }

    // Attack with damage
    void attack(int damage) {
        cout << "You hit the rock for " << damage 
             << " damage! The rock remains unimpressed." << endl;
    }

    // Magical attack with spell + damage
    void attack(string spell, int damage) {
        cout << "You cast " << spell << " and deal " << damage 
             << " magical damage! The rock glows briefly... then nothing happens." 
             << endl;
    }
};

int main() {
    Warrior hero;

    hero.attack();                    // basic attack
    hero.attack(15);                  // physical attack
    hero.attack("Fireball", 50);      // magical attack

    return 0;
}