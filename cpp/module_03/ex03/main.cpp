/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:42:20 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/16 18:47:35 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap diamond("Diamond");
    diamond.attack("enemy");
    diamond.takeDamage(5);
    diamond.beRepaired(3);
    diamond.attack("enemy");
    diamond.takeDamage(2);
    diamond.whoAmI();
    diamond.beRepaired(8);
    diamond.takeDamage(222);
    
    return 0;
}