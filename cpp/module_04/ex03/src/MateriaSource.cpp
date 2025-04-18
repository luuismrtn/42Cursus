/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:37:01 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 13:52:20 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource() : _count(0)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src) : _count(src._count)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = src._inventory[i];
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->_inventory[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
    if (this != &src)
    {
        this->_count = src._count;
        for (int i = 0; i < 4; i++)
            delete this->_inventory[i];
        for (int i = 0; i < 4; i++)
            this->_inventory[i] = src._inventory[i];
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (this->_count < 4 && m)
    {
        this->_inventory[this->_count] = m->clone();
        this->_count++;
        delete m;
    }
    else if (m)
    {
        delete m;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < this->_count; i++)
    {
        if (this->_inventory[i]->getType() == type)
            return this->_inventory[i]->clone();
    }
    return NULL;
}
