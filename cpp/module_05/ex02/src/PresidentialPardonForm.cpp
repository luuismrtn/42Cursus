/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:04:25 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/17 13:42:17 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <fstream>
#include <stdlib.h>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("Default Target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src), _target(src._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return *this;
}

void PresidentialPardonForm::performAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
