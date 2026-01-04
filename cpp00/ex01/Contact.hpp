#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _darkestSecret;
        std::string _phoneNumber;
    public:
        void setFirstName(std::string firstName);
        void setLastName(std:: string lastName);
        void setNickname(std:: string nickname);
        void setDarkestSecret(std:: string darkestSecret);
        void setPhoneNumber(std:: string phoneNumber);
        
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getDarkestSecret() const;
        std::string getPhoneNumber() const;

};

#endif