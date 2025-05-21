/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:12:50 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/21 13:59:44 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &src);
        ~Dog();
        Dog &operator=(const Dog &rhs);

        void makeSound() const;
};

#endif
