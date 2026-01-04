#include "Harl.hpp"

void Harl::_debug(){
    std::cout << "I love extra bacon on my burger!\n"<<std::endl;
}

void Harl::_info(){
    std::cout <<"I've been coming here for years!\n"<<std::endl;
}

void Harl::_warning(){
    std::cout <<"I think I deserve some for free!\n"<<std::endl;
}

void Harl::_error(){
    std::cout <<"This is unacceptable! I want to speak to the manager!\n"<<std::endl;
}

int get_level_index(std::string level) {
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

void Harl::complain(std::string level) {
    int index = get_level_index(level);

    switch (index) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            this->_debug();
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            this->_info();
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            this->_warning();
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            this->_error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}