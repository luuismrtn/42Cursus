/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:19:55 by lumartin          #+#    #+#             */
/*   Updated: 2025/09/25 15:28:09 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Bureaucrat.hpp"
#include "./inc/AForm.hpp"
#include "./inc/ShrubberyCreationForm.hpp"
#include "./inc/RobotomyRequestForm.hpp"
#include "./inc/PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "1. Test ShrubberyCreationForm" << std::endl;
	Bureaucrat Mr_ONE("Mr_ONE", 130);
	ShrubberyCreationForm Shrubby_form("I am a shrubbery form");
	std::cout << std::endl;
	std::cout << Shrubby_form;
	Mr_ONE.signForm(Shrubby_form);
	std::cout << Shrubby_form;
	Mr_ONE.executeForm(Shrubby_form);

	std::cout << std::endl << "2. Test RobotomyRequestForm" << std::endl;

	Bureaucrat Mr_TWO("Mr_TWO", 45);
	RobotomyRequestForm Robo_form("I am a robo form");

	Mr_TWO.executeForm(Robo_form);
	Mr_TWO.signForm(Robo_form);
	Mr_TWO.executeForm(Robo_form);
	Mr_TWO.executeForm(Robo_form);
	Mr_TWO.executeForm(Robo_form);

	std::cout << std::endl << "3. Test PresidentialPardonForm" << std::endl;
	PresidentialPardonForm President_form("I am a president form");
	Bureaucrat Mr_President("Mr_President", 5);

	Mr_TWO.executeForm(President_form);
	Mr_TWO.signForm(President_form);

	Mr_President.executeForm(President_form);
	Mr_President.signForm(President_form);
	Mr_President.executeForm(President_form);
	return (0);
}
