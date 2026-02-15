#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << std::endl << "Testing array of animals:" << std::endl;
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    for (int k = 0; k < numAnimals; ++k) {
        if (k % 2 == 0) {
            animals[k] = new Dog();
        } else {
            animals[k] = new Cat();
        }
    }

    for (int k = 0; k < numAnimals; ++k) {
        delete animals[k];
    }

    std::cout << std::endl << "Testing deep copy:" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase the ball");
    Dog dog2 = dog1;  
    dog2.getBrain()->setIdea(0, "Eat the ball");

    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

    Cat cat1;
    cat1.getBrain()->setIdea(0, "Sleep on keyboard");
    Cat cat2;
    cat2 = cat1;
    cat2.getBrain()->setIdea(0, "Knock over glass");

    std::cout << "Cat1 idea: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea: " << cat2.getBrain()->getIdea(0) << std::endl;

    return 0;
}