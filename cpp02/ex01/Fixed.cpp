#include "Fixed.hpp"
#include <iostream>
#include <cmath>


Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const int val) {
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = val << _fractionalBits;
}

Fixed::Fixed(const float val) {
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(val * (1 << _fractionalBits));
}


int Fixed::getRawBits(void) const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_rawBits >> _fractionalBits;
}


std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}