#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("CLP-42");

    clap.attack("a training dummy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    

    for (int i = 0; i < 10; i++) {
        clap.attack("the air");
    }

    clap.takeDamage(20);
    clap.beRepaired(10);

    return 0;
}