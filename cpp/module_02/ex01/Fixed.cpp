/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:01:54 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/15 17:37:40 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fixedPointValue = src.getRawBits();
    return *this;
}

Fixed::Fixed(const int input)
{
	std::cout << "Int Constructor called" << std::endl;
	this->_fixedPointValue = input << this->_fractionalBits;
}

Fixed::Fixed(const float input)
{
	std::cout << "Float Constructor called" << std::endl;
	this->_fixedPointValue = roundf(input * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
    return this->_fixedPointValue >> _fractionalBits;
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