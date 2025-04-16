/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:42:20 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/16 18:04:29 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap defaultClapTrap;
    ClapTrap juan("Juan");
    
    defaultClapTrap.setName("enemy");
    juan.attack("enemy");
    defaultClapTrap.takeDamage(5);
    defaultClapTrap.beRepaired(3);
    juan.attack("enemy");
    defaultClapTrap.takeDamage(2);
    defaultClapTrap.beRepaired(8);
    defaultClapTrap.attack("Juan");
    juan.takeDamage(8);
    juan.beRepaired(5);
    defaultClapTrap.attack("Juan");
    juan.takeDamage(7);
    
    return 0;
}