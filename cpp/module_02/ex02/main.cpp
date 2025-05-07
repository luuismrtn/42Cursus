/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:54:27 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/07 17:44:27 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << b - a << std::endl;
    
    std::cout << Fixed::min(a, b) << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}

