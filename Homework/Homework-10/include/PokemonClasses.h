#ifndef POKEMONCLASSES_H
#define POKEMONCLASSES_H

#include "ElectricPokemon.h"
#include "Pokemon.h"

// ================= Pikachu =================
class Pikachu : public ElectricPokemon {
public:
    Pikachu(int level)
        : ElectricPokemon("Pikachu", level) {}

    void attack() const override {
        std::cout << name << " uses Thunderbolt!" << std::endl;
    }

    void defend() const override {
        std::cout << name << " dodges quickly!" << std::endl;
    }

    void evolve() override {
        std::cout << name << " evolves into Raichu!" << std::endl;
    }
};

// ================= Charmander =================
class Charmander : public Pokemon {
public:
    Charmander(int level) : Pokemon("Charmander", level) {}

    void attack() const override {
        std::cout << name << " uses Flamethrower!" << std::endl;
    }

    void defend() const override {
        std::cout << name << " shields itself with fire!" << std::endl;
    }

    void evolve() override {
        std::cout << name << " evolves into Charmeleon!" << std::endl;
    }
};

// ================= Bulbasaur =================
class Bulbasaur : public Pokemon {
public:
    Bulbasaur(int level) : Pokemon("Bulbasaur", level) {}

    void attack() const override {
        std::cout << name << " uses Vine Whip!" << std::endl;
    }

    void defend() const override {
        std::cout << name << " hides behind thick leaves!" << std::endl;
    }

    void evolve() override {
        std::cout << name << " evolves into Ivysaur!" << std::endl;
    }
};

#endif
