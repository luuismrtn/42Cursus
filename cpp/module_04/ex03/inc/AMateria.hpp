/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:16:43 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 13:44:34 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
        
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(AMateria const &src);
        virtual ~AMateria();
        AMateria &operator=(AMateria const &src);
        std::string const &getType() const;
        
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif
