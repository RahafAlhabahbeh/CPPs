#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip> 
#include <cctype>

 PhoneBook::PhoneBook() :_index(0), _count(0){}


 bool is_numeric(std::string str) {
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}


 void PhoneBook::addContact() {
    std::string input;
    Contact     newContact;

    while (input.empty()) {
        std::cout << "Enter First Name: ";
        if (!std::getline(std::cin, input)) 
            return;
        if (input.empty())
            std::cout << "First Name can't be empty" << std::endl;
    }
    newContact.setFirstName(input);
    input.clear();

    while (input.empty()) {
        std::cout << "Enter Last Name: ";
        if (!std::getline(std::cin, input)) return;
        if (input.empty())
            std::cout << "Last Name can't be empty" << std::endl;
    }
    newContact.setLastName(input);
    input.clear();

    while (input.empty()) {
        std::cout << "Enter Nickname: ";
        if (!std::getline(std::cin, input)) return;
        if (input.empty())
            std::cout << "Nickname can't be empty" << std::endl;
            
    }
    newContact.setNickname(input);
    input.clear();

    while (true) {
       std::cout << "Enter Phone Number: ";
       if (!std::getline(std::cin, input)) return;

       if (input.empty()) {
           std::cout << "Field cannot be empty." << std::endl;
       } else if (!is_numeric(input)) {
           std::cout << "Invalid input. Please enter digits only." << std::endl;
       }else if (input.length() != 10){
            std::cout << "Field the phonenumber must have 10 digits." << std::endl;
       } else {
           newContact.setPhoneNumber(input);
           input.clear();
           break; 
       }
    }

    while (input.empty()) {
        std::cout << "Enter Darkest Secret: ";
        if (!std::getline(std::cin, input)) return;
        if (input.empty())
        std::cout << "Dark Secret can't be empty" << std::endl;
    }
    newContact.setDarkestSecret(input);
    input.clear();

    this->_contacts[this->_index] = newContact;

    this->_index = (this->_index + 1) % 8;

    if (this->_count < 8)
        this->_count++;

    std::cout << "Contact added successfully!" << std::endl;
}

std::string formatColumn(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::searchContact() {
    if (this->_count == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << "|" << std::setw(10) << "Index" 
              << "|" << std::setw(10) << "First Name" 
              << "|" << std::setw(10) << "Last Name" 
              << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < this->_count; i++) {
        std::cout << "|" << std::setw(10) << i 
                  << "|" << std::setw(10) << formatColumn(_contacts[i].getFirstName())
                  << "|" << std::setw(10) << formatColumn(_contacts[i].getLastName())
                  << "|" << std::setw(10) << formatColumn(_contacts[i].getNickname()) << "|" << std::endl;
    }

    std::string input;
    std::cout << "\nEnter index to display details: ";
    if (!(std::getline(std::cin, input))) return;

    if (input.length() == 1 && input[0] >= '0' && input[0] < '0' + _count) {
        int i = input[0] - '0';
        std::cout << "\nFirst Name: " << _contacts[i].getFirstName() << std::endl;
        std::cout << "Last Name: " << _contacts[i].getLastName() << std::endl;
        std::cout << "Nickname: " << _contacts[i].getNickname() << std::endl;
        std::cout << "Phone Number: " << _contacts[i].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << _contacts[i].getDarkestSecret() << std::endl;
    } else {
        std::cout << "Invalid index!" << std::endl;
    }
}