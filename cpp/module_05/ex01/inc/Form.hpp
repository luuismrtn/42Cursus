/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:34:15 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/16 20:48:32 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _executeGrade;

    public:
        Form(const std::string &name, int signGrade, int executeGrade);
        Form(const Form &src);
        virtual ~Form();

        Form &operator=(const Form &src);

        const std::string &getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Form const &other);

#endif
