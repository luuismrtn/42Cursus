/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:54:27 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/07 17:46:32 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"

Fixed getArea(Point const a, Point const b, Point const c)
{
    return Fixed((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed u = getArea(point, b, c) / getArea(a, b, c);
    Fixed v = getArea(a, point, c) / getArea(a, b, c);
    Fixed w = getArea(a, b, point) / getArea(a, b, c);

    if (u < 0 || v < 0 || w < 0)
        return false;

    if (u + v + w > 1)
        return false;
    
    return true;
    
}

int main(void)
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point point(0, 1);

    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    return 0;
}
