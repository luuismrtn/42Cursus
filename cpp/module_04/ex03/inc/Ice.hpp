/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:20:57 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/21 14:20:24 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#ifndef ICE_HPP
#define ICE_HPP

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const &src);
        virtual ~Ice();
        Ice &operator=(Ice const &src);
        
        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
};

#endif
