/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:34:15 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/17 13:29:42 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _executeGrade;
        virtual void	performAction() const = 0;

    public:
        AForm(const std::string &name, int signGrade, int executeGrade);
        AForm(const AForm &src);
        virtual ~AForm();

        AForm &operator=(const AForm &src);

        const std::string &getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void execute(const Bureaucrat &executor) const;
        void beSigned(const Bureaucrat &bureaucrat);

        class isNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

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

std::ostream &operator<<(std::ostream &os, AForm const &other);

#endif
