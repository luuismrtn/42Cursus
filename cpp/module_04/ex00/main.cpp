/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:08:11 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 12:26:18 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./inc/Animal.hpp"
#include "./inc/Cat.hpp"
#include "./inc/Dog.hpp"
#include "./inc/WrongAnimal.hpp"
#include "./inc/WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    
    std::cout << "\n----- Pruebas del subject -----\n" << std::endl;
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    std::cout << "\n----- Pruebas con WrongAnimal y WrongCat -----\n" << std::endl;
    
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();
    
    std::cout << "WrongAnimal type: " << wrongMeta->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    
    std::cout << "WrongAnimal sound: ";
    wrongMeta->makeSound();
    
    std::cout << "WrongCat sound: ";
    wrongCat->makeSound();
    
    const WrongCat directWrongCat;
    std::cout << "WrongCat sound (directo): ";
    directWrongCat.makeSound();

    std::cout << "\n----- Destructores -----\n" << std::endl;
    
    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongCat;
    
    return 0;
}