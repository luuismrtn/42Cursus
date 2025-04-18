/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:10:29 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 12:10:41 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef CAT_HPP
#define CAT_HPP

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &src);
        ~Cat();
        Cat &operator=(const Cat &rhs);

        void makeSound() const;
};

#endif