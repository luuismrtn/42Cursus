/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:10:29 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/21 14:14:59 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
#define CAT_HPP

class Cat : public AAnimal
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat &src);
        ~Cat();
        Cat &operator=(const Cat &src);

        void makeSound() const;
        Brain *getBrain() const;
        void setBrain(Brain *brain);
};

#endif
