/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:01:54 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/07 17:37:26 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}

Fixed::Fixed(const int input)
{
	this->_fixedPointValue = input << this->_fractionalBits;
}

Fixed::Fixed(const float input)
{
	this->_fixedPointValue = roundf(input * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
}

float Fixed::toFloat( void ) const
{
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    if (this != &src)
        this->_fixedPointValue = src.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &src) const
{
    return this->_fixedPointValue > src._fixedPointValue;
}

bool Fixed::operator<(const Fixed &src) const
{
    return this->_fixedPointValue < src._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &src) const
{
    return this->_fixedPointValue >= src._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &src) const
{
    return this->_fixedPointValue <= src._fixedPointValue;
}

bool Fixed::operator==(const Fixed &src) const
{
    return this->_fixedPointValue == src._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &src) const
{
    return this->_fixedPointValue != src._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &src) const
{
    return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
    return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
    return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
    return Fixed(this->toFloat() / src.toFloat());
}

Fixed Fixed::operator++( void )
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed temp = *this;
    this->_fixedPointValue++;
    return temp;
}

Fixed Fixed::operator--( void )
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--( int )
{
    Fixed temp = *this;
    this->_fixedPointValue--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
