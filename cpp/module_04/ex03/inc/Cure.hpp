/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:20:21 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/21 14:20:15 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#ifndef CURE_HPP
#define CURE_HPP

class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const &src);
        virtual ~Cure();
        Cure &operator=(Cure const &src);
        
        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
};

#endif
