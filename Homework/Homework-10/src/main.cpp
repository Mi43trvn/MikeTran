/*
---Inheritance is one in which a new class is created that inherits the properties of the 
already exist class. It supports the concept of code reusability and reduces the length 
of the code in object-oriented programming.


--Polymorphism is that in which we can perform a task in multiple 
forms or ways. It is applied to the functions or methods
*/

#include "Pokemon.h"
#include "PokemonClasses.h"
#include "Dito.h"
#include "printHeader.h"

int main() {
  
    Pikachu pikachu(10);
    Charmander charmander(12);
    Bulbasaur bulbasaur(8);
    // Create instances of derived classes
  // Pokemon dito("dito",9000);  // error
    Dito dito(9000,&bulbasaur);

    // Array of pointers to base class, demonstrating polymorphism
    Pokemon* pokemons[] = { &pikachu, &charmander, &bulbasaur, &dito };

    // Print header
    printHeader("Pokemon Battle");

    // Loop through the array and call functions polymorphically
    for (Pokemon* h : pokemons) {
        h->display();  // Calls the base class function
        h->attack();   // Calls the derived class function
        std::cout << std::endl;
    }

    return 0;
}
