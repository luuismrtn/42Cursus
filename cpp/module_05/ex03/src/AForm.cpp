/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:36:34 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/17 13:29:09 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &src)
    : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
    {
        _isSigned = src._isSigned;
    }
    return *this;
}

const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecuteGrade() const
{
    return _executeGrade;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw isNotSignedException();
    if (executor.getGrade() > _executeGrade)
        throw GradeTooLowException();

    performAction();
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char *AForm::isNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, AForm const &other)
{
    os << "AForm: " << other.getName()
       << ", Signed: " << (other.isSigned() ? "Yes" : "No")
       << ", Sign Grade: " << other.getSignGrade()
       << ", Execute Grade: " << other.getExecuteGrade() << std::endl;
    return os;
}
