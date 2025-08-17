/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:08:11 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/16 20:32:03 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./inc/Bureaucrat.hpp"

int main(void)
{
    std::cout << "High and Low Bureaucrat Test" << std::endl;
    
    try
    {
        Bureaucrat Top("Luisón", 1500);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat Down("Luisito", -10);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "Test increasing" << std::endl;
    
    Bureaucrat pepe("Pepe", 2);
    std::cout << pepe;
    try
    {
        pepe.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << pepe;

    try
    {
        pepe.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << pepe << std::endl;

    std::cout << "Test decreasing" << std::endl;

    Bureaucrat tobias("Tobias", 149);

    std::cout << tobias;
    
    try
    {
        tobias.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << tobias;

    try
    {
        tobias.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << tobias;

    return (0);
}
