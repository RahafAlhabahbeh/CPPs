#include "ScavTrap.hpp"

int main() {
    std::cout << "--- Creating ClapTrap ---" << std::endl;
    ClapTrap clap("Basic");
    
    std::cout << "\n--- Creating ScavTrap ---" << std::endl;
    ScavTrap scav("Guardian");

    std::cout << "\n--- Testing ScavTrap Functions ---" << std::endl;
    scav.attack("an intruder");
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n--- Destruction sequence ---" << std::endl;
    return 0;
}