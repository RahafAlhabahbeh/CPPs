#include "Zombie.hpp"

int main(void) {
    // Heap allocation
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    // Stack allocation
    randomChump("StackZombie");

    return 0;
}