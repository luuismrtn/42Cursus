/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:04:25 by lumartin          #+#    #+#             */
/*   Updated: 2025/09/25 15:28:17 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return *this;
}

void ShrubberyCreationForm::performAction() const
{
    std::ofstream outFile((_target + std::string("_shrubbery")).c_str());
    
    if (outFile)
    {
        outFile << "    /\\    \n";
        outFile << "   /  \\   \n";
        outFile << "  /    \\  \n";
        outFile << " /      \\ \n";
        outFile << "/________\\\n";
        outFile << "    ||    \n";
        outFile << "    ||    \n";
        outFile << "    ||    \n";

        outFile.close();
    }
    else
        throw ShrubberyCreationForm::FileOpenException();
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "Could not open file for writing!";
}
