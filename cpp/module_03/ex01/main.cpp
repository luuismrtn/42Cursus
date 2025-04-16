/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:42:20 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/16 18:34:13 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap marcos;
    ClapTrap juan("Juan");
    
    marcos.setName("marcos");
    juan.attack("marcos");
    marcos.takeDamage(5);
    marcos.beRepaired(3);
    marcos.attack("juan");
    juan.takeDamage(2);
    marcos.beRepaired(8);
    marcos.guardGate();
    marcos.attack("Juan");
    juan.takeDamage(8);
    
    return 0;
}