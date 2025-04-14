/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:13:02 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/14 15:26:52 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
    int N = 5;
    Zombie *horde = zombieHorde(N, "Zombie");
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;

    return 0;
}