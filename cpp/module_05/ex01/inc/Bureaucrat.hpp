/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:14:13 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/16 20:48:01 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &src);

        const std::string &getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);

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

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);

#endif
