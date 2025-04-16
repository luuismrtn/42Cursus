/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:42:20 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/16 18:34:30 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ScavTrap scavTrap("Scavvy");
    FragTrap fragTrap("Fraggy");
    
    scavTrap.attack("Fraggy");
    fragTrap.takeDamage(8);
    fragTrap.beRepaired(5);
    fragTrap.highFivesGuys();
    scavTrap.guardGate();
    fragTrap.attack("Scavvy");
    scavTrap.takeDamage(10);
    
    return 0;
}