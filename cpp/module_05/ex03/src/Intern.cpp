/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:47:22 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/17 14:12:35 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string form_name, const std::string form_target)
{
    int i = 0;
    std::string available_forms[] = {"shrubbery", "robotomy", "presidential"};
    std::string lowercase_form_name = form_name;
    
    for (size_t j = 0; j < lowercase_form_name.length(); j++)
    {
        lowercase_form_name[j] = std::tolower(lowercase_form_name[j]);
    }

    while (i < 3)
    {
        if (lowercase_form_name.find(available_forms[i]) != std::string::npos)
            break;
        i++;
    }

    switch (i)
    {
    case 0:
        std::cout << "Intern creates ShrubberyCreationForm " << std::endl;
        return (new ShrubberyCreationForm(form_target));
    case 1:
        std::cout << "Intern creates RobotomyRequestForm " << std::endl;
        return (new RobotomyRequestForm(form_target));
    case 2:
        std::cout << "Intern creates PresidentialPardonForm " << std::endl;
        return (new PresidentialPardonForm(form_target));
    default:
        std::cout << "Form is not existing" << std::endl;
        return NULL;
    }
}
