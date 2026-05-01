#ifndef POKEMONTYPE_H
#define POKEMONTYPE_H

#include "Pokemon.h"

class PokemonType : public Pokemon {
protected:
    std::string typeName;

public:
    PokemonType(const std::string& name, int level, const std::string& type)
        : Pokemon(name, level), typeName(type) {}

    std::string getType() const { return typeName; }
};

#endif
