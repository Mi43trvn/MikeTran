#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

// Abstract base class representing a generic Pokemon
//Note: An abstract class is one that has at least one 
//pure virtual function attack() function is a pure virtual function.
class Pokemon {
protected:
    std::string name;
    int level;

public:
    // Constructor to initialize name and level
    Pokemon(const std::string& name, int level) : name(name), level(level) {}

    // Virtual destructor to ensure proper cleanup of derived class objects
    virtual ~Pokemon() {
        std::cout<<"Your "+name+" has fainted!"<<std::endl;
    }

    // Pure virtual function to be overridden by derived classes
    virtual void attack() const = 0;

    // Function to display the Pokemon's details
    void display() const {
        std::cout << "Name: " << name << ", Level: " << level << std::endl;
    }
};

#endif // POKEMON_H
