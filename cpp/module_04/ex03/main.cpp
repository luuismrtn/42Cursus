/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:16:13 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/21 14:43:09 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./inc/ICharacter.hpp"
#include "./inc/AMateria.hpp"
#include "./inc/Ice.hpp"
#include "./inc/Cure.hpp"
#include "./inc/Character.hpp"
#include "./inc/MateriaSource.hpp"

int main()
{
    {
        std::cout << "\n----- Subject Test -----\n" << std::endl;
        
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        ICharacter *me = new Character("me");

        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        ICharacter *bob = new Character("bob");
        
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
        
    }
    {
        std::cout << "\n----- My Test -----\n" << std::endl;

        IMateriaSource *src = new MateriaSource();
        
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        
        ICharacter *me = new Character("me");
        ICharacter *bob = new Character("bob");
        AMateria *ice = src->createMateria("ice");

        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = ice->clone();
        me->equip(tmp);

        me->use(0, *bob);
        me->use(1, *bob);
        me->use(2, *bob);
        me->use(3, *bob);
        me->unequip(2);
        me->use(2, *bob);
        
        delete bob;
        delete me;
        delete src;
        delete ice;
    }
}
