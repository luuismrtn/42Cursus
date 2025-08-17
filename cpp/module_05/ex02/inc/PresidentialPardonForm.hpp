/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:03:29 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/17 13:41:14 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string   _target;
        virtual void performAction() const;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        virtual ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
};


#endif
