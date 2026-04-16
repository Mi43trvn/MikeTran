#ifndef POKEMONTYPES_H
#define POKEMONTYPES_H

#include "Pokemon.h"

// Pikachu class derived from Pokemon
class Pikachu : public Pokemon {
public:
    Pikachu(int level) : Pokemon("Pikachu", level) {}

    // Override the attack function to provide specific behavior
    void attack() const override {
        std::cout << name << " uses Thunderbolt!" << std::endl;
    }
    ~Pikachu() {
        std::cout << name << " you put up a good fight return to the ball" << std::endl;
    }
};

// Charmander class derived from Pokemon
class Charmander : public Pokemon {
public:
    Charmander(int level) : Pokemon("Charmander", level) {}

    // Override the attack function to provide specific behavior
    void attack() const override {
        std::cout << name << " uses Flamethrower!" << std::endl;
    }
};

// Bulbasaur class derived from Pokemon
class Bulbasaur : public Pokemon {
public:
    Bulbasaur(int level) : Pokemon("Bulbasaur", level) {}

    // Override the attack function to provide specific behavior
    void attack() const override {
        std::cout << name << " uses Vine Whip!" << std::endl;
    }
};

#endif // POKEMONTYPES_H
