/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:08:11 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 13:11:09 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./inc/AAnimal.hpp"
#include "./inc/Cat.hpp"
#include "./inc/Dog.hpp"
#include "./inc/Brain.hpp"

int main()
{
    std::cout << "\n----- Trying create an Animal -----\n" << std::endl;

    //AAnimal *animal = new AAnimal();

    std::cout << "\n----- Creating animal array -----\n" << std::endl;
    
    const int numAnimals = 10;
    AAnimal *animals[numAnimals];
    
    for (int i = 0; i < numAnimals / 2; i++) {
        std::cout << "Creating Dog " << i << std::endl;
        animals[i] = new Dog();
    }
    
    for (int i = numAnimals / 2; i < numAnimals; i++) {
        std::cout << "Creating Cat " << i << std::endl;
        animals[i] = new Cat();
    }
    
    std::cout << "\n----- Deep copy test -----\n" << std::endl;
    
    Dog *originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "Dog's original idea");
    
    Dog *copyDog = new Dog(*originalDog);
    std::cout << "Original idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea: " << copyDog->getBrain()->getIdea(0) << std::endl << std::endl;
    
    copyDog->getBrain()->setIdea(0, "New idea in the copy");
    std::cout << "After changing the idea in the copy:" << std::endl;
    std::cout << "Original idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea: " << copyDog->getBrain()->getIdea(0) << std::endl << std::endl;
    
    Cat *originalCat = new Cat();
    originalCat->getBrain()->setIdea(0, "Cat's original idea");
    
    Cat *copyCat = new Cat(*originalCat);
    std::cout << "Original idea: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea: " << copyCat->getBrain()->getIdea(0) << std::endl << std::endl;
    
    copyCat->getBrain()->setIdea(0, "New idea in the copy");
    std::cout << "After changing the idea in the copy:" << std::endl;
    std::cout << "Original idea: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea: " << copyCat->getBrain()->getIdea(0) << std::endl << std::endl;
    
    std::cout << "\n----- Deleting animals -----\n" << std::endl;
    
    for (int i = 0; i < numAnimals; i++) {
        std::cout << "Deleting animal " << i << std::endl;
        delete animals[i];
    }
    
    std::cout << "Deleting original dog" << std::endl;
    delete originalDog;
    std::cout << "Deleting dog copy" << std::endl;
    delete copyDog;
    std::cout << "Deleting original cat" << std::endl;
    delete originalCat;
    std::cout << "Deleting cat copy" << std::endl;
    delete copyCat;
    
    std::cout << "\n----- End of program -----\n" << std::endl;
    
    // Memory leak verification (run with valgrind)
    // valgrind --leak-check=full ./animal
    
    return 0;
}