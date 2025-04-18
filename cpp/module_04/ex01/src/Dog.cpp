/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:13:04 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 12:56:55 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain(*src._brain);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &src)
    {
        Animal::operator=(src);
        delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Guau" << std::endl;
}

Brain *Dog::getBrain() const
{
    return this->_brain;
}

void Dog::setBrain(Brain *brain)
{
    if (this->_brain)
        delete this->_brain;
    this->_brain = brain;
}