/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:04:07 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/07 17:47:58 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point();
        Point(const Point &src);
        Point(const Fixed &x, const Fixed &y);
        
        Point &operator=(const Point &src);
        ~Point();
        
        Fixed getX( void ) const;
        Fixed getY( void ) const;
    };


#endif
