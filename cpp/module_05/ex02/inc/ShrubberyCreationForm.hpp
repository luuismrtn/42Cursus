/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:03:29 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/17 13:16:20 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string   _target;
        virtual void performAction() const;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

        class FileOpenException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};


#endif
