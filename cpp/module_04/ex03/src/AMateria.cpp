/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:21:25 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 13:46:41 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"

AMateria::AMateria() : _type("default")
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(AMateria const &src)
{
    *this = src;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(AMateria const &src)
{
    if (this != &src)
        this->_type = src._type;
    return *this;
}

std::string const &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses " << this->_type << " on " << target.getName() << " *" << std::endl;
}
