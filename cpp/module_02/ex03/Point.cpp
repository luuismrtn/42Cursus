/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:14:13 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/15 18:34:20 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y)
{
}

Point &Point::operator=(const Point &src)
{
    if (this != &src)
    {
        return *this;
    }
	return *this;
}

Point::~Point()
{
}

Fixed Point::getX( void ) const
{
    return this->_x;
}

Fixed Point::getY( void ) const
{
    return this->_y;
}
