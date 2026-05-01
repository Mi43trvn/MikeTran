#ifndef ELECTRICPOKEMON_H
#define ELECTRICPOKEMON_H

#include "PokemonType.h"

class ElectricPokemon : public PokemonType {
public:
    ElectricPokemon(const std::string& name, int level)
        : PokemonType(name, level, "Electric") {}

    void attack() const override {
        std::cout << name << " releases a burst of electricity!" << std::endl;
    }

    void defend() const override {
        std::cout << name << " surrounds itself with static energy!" << std::endl;
    }

    void evolve() override {
        std::cout << name << " is glowing with electric power..." << std::endl;
    }
};

#endif
