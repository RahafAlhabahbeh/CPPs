#include "Zombie.hpp"

void randomChump(std::string name) {
    // This is the "Direct Initialization" way:
    Zombie stackZombie(name); 

    // Now make the zombie speak
    stackZombie.announce();

    // No 'delete' here! 
    // The moment we hit the '}', stackZombie is removed from the stack
    // and its destructor is automatically called.
}