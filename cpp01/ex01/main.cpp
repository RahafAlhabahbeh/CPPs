#include "Zombie.hpp"

int main() {

    // std::cout << "--- Testing Single Stack Zombie ---" << std::endl;
    // Zombie stackZombie("Stacky");
    // stackZombie.announce();

    // std::cout << "\n--- Testing Single Heap Zombie ---" << std::endl;
    // Zombie *heapZombie = new Zombie("Heapy");
    // heapZombie->announce();
    // delete heapZombie;

    int N = 5;
    Zombie* horde = zombieHorde(N, "HordeMember");

    if (horde) {
        for (int i = 0; i < N; i++) {
            horde[i].announce();
        }
        delete[] horde; // CRITICAL: Use delete[] for arrays
    }

    return 0;
}