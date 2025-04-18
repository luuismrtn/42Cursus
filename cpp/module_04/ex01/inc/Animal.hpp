/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:08:56 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 12:54:42 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;

    public:

        Animal();
        Animal(const Animal &src);
        virtual ~Animal();
        Animal &operator=(const Animal &src);

        virtual void makeSound() const;
        std::string getType() const;
};

#endif