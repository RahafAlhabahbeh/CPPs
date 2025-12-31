#include "Zombie.hpp"

void  Zombie::setName(std::string name){
    this->_name = name;
}

Zombie::~Zombie() {
    std::cout << this->_name << ": has been destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {
    this->_name = "Unnamed"; 
}

Zombie::Zombie(std::string name) {
    this->_name = name;
}