/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:20:20 by lumartin          #+#    #+#             */
/*   Updated: 2025/12/03 16:29:29 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <list of non-negative integers>" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    try
    {
        sorter.parseInput(argc, argv);
        sorter.sortAndTime();
        std::cout << "Before: ";
        for (int i = 1; i < argc; ++i)
        {
            std::istringstream iss(argv[i]);
            int number;
            iss >> number;
            std::cout << number << " ";
        }
        std::cout << std::endl;
        sorter.printContainers();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
