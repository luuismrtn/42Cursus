/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:34:52 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 13:49:06 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character() : _name("default"), _count(0)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name), _count(0)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(Character const &src) : _name(src._name), _count(src._count)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = src._inventory[i];
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete this->_inventory[i];
}

Character &Character::operator=(Character const &src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_count = src._count;
        for (int i = 0; i < 4; i++)
            delete this->_inventory[i];
        for (int i = 0; i < 4; i++)
            this->_inventory[i] = src._inventory[i];
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    if (this->_count < 4 && m)
    {
        this->_inventory[this->_count] = m;
        this->_count++;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        delete this->_inventory[idx];
        this->_inventory[idx] = NULL;
        this->_count--;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
}
