/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:03:29 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/17 13:36:14 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string   _target;
        virtual void performAction() const;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

        class RobotizationFailed : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};


#endif
