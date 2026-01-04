#include "Harl.hpp"

void Harl::_debug(){
    std::cout << "I love extra bacon on my burger!"<<std::endl;
}

void Harl::_info(){
    std::cout <<"I've been coming here for years!"<<std::endl;
}

void Harl::_warning(){
    std::cout <<"I think I deserve some for free!"<<std::endl;
}

void Harl::_error(){
    std::cout <<"This is unacceptable! I want to speak to the manager!"<<std::endl;
}

void Harl::complain(std::string level) {

    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    void (Harl::*functions[])(void) = {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}