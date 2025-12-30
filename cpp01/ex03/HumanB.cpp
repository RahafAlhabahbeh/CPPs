#include "HumanB.hpp"

// We initialize the pointer to NULL (or 0) because they start unarmed
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon; // Take the address of the weapon reference
}

void HumanB::attack() const {
    if (this->_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    } else {
        std::cout << _name << " has no weapon to attack with!" << std::endl;
    }
}