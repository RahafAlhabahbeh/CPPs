#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int     _index;
        int     _count;
    public:
        PhoneBook();
        void addContact();
        void searchContact();
};

#endif