/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:37:54 by lumartin          #+#    #+#             */
/*   Updated: 2025/09/25 15:27:40 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Bureaucrat.hpp"
#include "./inc/Form.hpp"

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

	std::cout << std::endl << "Form and Bureaucrat interaction" << std::endl;

	Form id_form("ID FORM", 100, 90);
	Bureaucrat sr_no;
	Bureaucrat sr_yes("SR_YES", 100);
	std::cout << id_form;
	
	sr_no.signForm(id_form);
	std::cout << id_form;

	sr_yes.signForm(id_form);
	std::cout << id_form;
	
	return (0);
}
