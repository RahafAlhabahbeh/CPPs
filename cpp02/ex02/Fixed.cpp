#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {}
Fixed::Fixed(const int val) : _rawBits(val << _fractionalBits) {}
Fixed::Fixed(const float val) : _rawBits(roundf(val * (1 << _fractionalBits))) {}
Fixed::Fixed(const Fixed &other) { *this = other; }
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) this->_rawBits = other.getRawBits();
    return *this;
}
Fixed::~Fixed() {}

int     Fixed::getRawBits(void) const { return this->_rawBits; }
void    Fixed::setRawBits(int const raw) { this->_rawBits = raw; }
float   Fixed::toFloat(void) const { return (float)this->_rawBits / (1 << _fractionalBits); }
int     Fixed::toInt(void) const { return this->_rawBits >> _fractionalBits; }

bool Fixed::operator>(const Fixed &other) const { return this->_rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed &other) const { return this->_rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed &other) const { return this->_rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed &other) const { return this->_rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed &other) const { return this->_rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed &other) const { return this->_rawBits != other._rawBits; }

Fixed Fixed::operator+(const Fixed &other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

Fixed& Fixed::operator++(void) { this->_rawBits++; return *this; }
Fixed Fixed::operator++(int) { Fixed tmp(*this); this->_rawBits++; return tmp; }
Fixed& Fixed::operator--(void) { this->_rawBits--; return *this; }
Fixed Fixed::operator--(int) { Fixed tmp(*this); this->_rawBits--; return tmp; }

Fixed& Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}