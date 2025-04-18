/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:08:56 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 13:07:05 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>
#include <string>

class AAnimal
{
    protected:
        std::string type;

    public:

        AAnimal();
        AAnimal(const AAnimal &src);
        virtual ~AAnimal();
        AAnimal &operator=(const AAnimal &src);

        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif