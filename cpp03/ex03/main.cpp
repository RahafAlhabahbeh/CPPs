#include "DiamondTrap.hpp"

int main() {
    std::cout << "--- 1. CONSTRUCTION PHASE ---" << std::endl;
    DiamondTrap monster("DI-MN0");
    std::cout << std::endl;

    std::cout << "--- 2. IDENTITY CHECK ---" << std::endl;
    monster.whoAmI();
    std::cout << std::endl;

    std::cout << "--- 3. ATTRIBUTE TESTS ---" << std::endl;
    monster.attack("a target dummy"); 
    
    monster.takeDamage(30);
    monster.beRepaired(20);
    std::cout << std::endl;

    std::cout << "--- 4. SPECIAL ABILITIES ---" << std::endl;
    monster.guardGate();
    monster.highFivesGuys();
    std::cout << std::endl;

    std::cout << "--- 5. ORTHODOX CANONICAL FORM TEST ---" << std::endl;
    DiamondTrap copy(monster);
    copy.whoAmI();
    std::cout << std::endl;

    std::cout << "--- 6. DESTRUCTION PHASE ---" << std::endl;
    return 0;
} 