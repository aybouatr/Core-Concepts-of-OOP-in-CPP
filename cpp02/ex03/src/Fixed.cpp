#include "../include/Fixed.hpp"


const int Fixed::_fract_bits = 8;

Fixed::Fixed(): _fp_value(0)
{
}

Fixed::Fixed(const int input)
{
	this->_fp_value = input << this->_fract_bits;
}

Fixed::Fixed(const float input)
{
	this->_fp_value = roundf(input * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}

float	Fixed::toFloat(void)const
{
	return ((float)this->_fp_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fp_value >> this->_fract_bits);
}

Fixed& Fixed::operator=(const Fixed& other) 
{
    if (this != &other)
        this->_fp_value = other._fp_value;
    return *this;
}

bool Fixed::operator==(const Fixed& other) 
{
     return (this->_fp_value == other._fp_value);
}

bool Fixed::operator!=(const Fixed& other) 
{
    return (this->_fp_value != other._fp_value);
}

bool Fixed::operator<(const Fixed& other)
{
    return (this->_fp_value < other._fp_value);
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->_fp_value > other._fp_value);
}

bool Fixed::operator<=(const Fixed& other) 
{
    return (this->_fp_value <= other._fp_value);
}

bool Fixed::operator>=(const Fixed& other) 
{
    return (this->_fp_value >= other._fp_value);
}

float Fixed::operator+(const Fixed& other)
{
	return (this->toFloat() + other.toFloat());
}

float Fixed::operator-(const Fixed& other)
{
	return (this->toFloat() - other.toFloat());
}

float Fixed::operator/(const Fixed& other)
{
	return (this->toFloat() / other.toFloat());
}

float Fixed::operator*(const Fixed& other)
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_fp_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_fp_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_fp_value++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_fp_value--;
	return (tmp);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}


Fixed& Fixed::max(Fixed& First,Fixed& second)
{
	if (First > second)
		return First;
	return (second);
}

const Fixed& Fixed::max(const Fixed& First,const Fixed& second)
{
	if (First > second)
		return First;
	return (second);
}