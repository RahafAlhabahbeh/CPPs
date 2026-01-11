#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "--- CREATION PHASE ---" << std::endl;
    FragTrap frag("FR4G-TP");
    
    std::cout << "\n--- ATTRIBUTE TESTING ---" << std::endl;
    frag.attack("a hyperion soldier");

    frag.takeDamage(50);
    frag.beRepaired(25);
    
    std::cout << "\n--- SPECIAL ABILITY ---" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n--- EXHAUSTION TEST ---" << std::endl;
    frag.takeDamage(150);
    frag.attack("the void");
    frag.beRepaired(10);

    std::cout << "\n--- DESTRUCTION PHASE ---" << std::endl;
    return 0;
}