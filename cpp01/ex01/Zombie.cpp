#include "Zombie.hpp"

void  Zombie::setName(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << this->name << ": has been destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {
    this->name = "Unnamed"; 
}

Zombie::Zombie(std::string name) {
    this->name = name;
}