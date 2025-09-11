/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:03:13 by lumartin          #+#    #+#             */
/*   Updated: 2025/09/11 19:57:13 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./inc/easyfind.hpp"
#include <vector>

int main(void)
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i * 10);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 50);
        std::cout << "The number " << *it << " was found in the container." << std::endl;
        
        std::vector<int>::iterator it2 = easyfind(vec, 49);
        std::cout << "The number " << *it2 << " was found in the container." << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
