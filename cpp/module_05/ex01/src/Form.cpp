/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:36:34 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/16 20:50:13 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &src)
    : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
}

Form::~Form() {}

Form &Form::operator=(const Form &src)
{
    if (this != &src)
    {
        _isSigned = src._isSigned;
    }
    return *this;
}

const std::string &Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _isSigned;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecuteGrade() const
{
    return _executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, Form const &other)
{
    os << "Form: " << other.getName() 
       << ", Signed: " << (other.isSigned() ? "Yes" : "No")
       << ", Sign Grade: " << other.getSignGrade()
       << ", Execute Grade: " << other.getExecuteGrade()
       << std::endl;
    return os;
}


