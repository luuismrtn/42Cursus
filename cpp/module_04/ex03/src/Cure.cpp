/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:23:02 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 13:47:15 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &src) : AMateria(src)
{
    *this = src;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(Cure const &src)
{
    if (this != &src)
        this->_type = src._type;
    return *this;
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}