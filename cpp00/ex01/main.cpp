#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook   book;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        
        if (!std::getline(std::cin, command)) {
            std::cout << std::endl;
            break;
        }

        if (command == "ADD") {
            book.addContact();
        } else if (command == "SEARCH") {
            book.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            if (!command.empty())
                std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}