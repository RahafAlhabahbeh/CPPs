#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA {
private:
    std::string _name;
    Weapon&     _weapon; // Reference: must always point to something

public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();

    void attack() const;
};

#endif