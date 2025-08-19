/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:08:11 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/19 20:59:20 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Base.hpp"
#include "./inc/A.hpp"
#include "./inc/B.hpp"
#include "./inc/C.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    std::cout << "\n--- Test Random Generation ---" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "\n Test " << (i + 1) << ":" << std::endl;
        Base *obj = generate();

        std::cout << "Pointer identification: ";
        identify(obj);

        std::cout << "Reference identification: ";
        identify(*obj);

        delete obj;
    }

    std::cout << "\n--- Test Specific Type ---" << std::endl;

    // Test A
    std::cout << "\nCreating object of type A:" << std::endl;
    Base *a = new A();
    std::cout << "With pointer: ";
    identify(a);
    std::cout << "With reference: ";
    identify(*a);
    delete a;
    
    // Test B
    std::cout << "\nCreating object of type B:" << std::endl;
    Base *b = new B();
    std::cout << "With pointer: ";
    identify(b);
    std::cout << "With reference: ";
    identify(*b);
    delete b;
    
    // Test C
    std::cout << "\nCreating object of type C:" << std::endl;
    Base *c = new C();
    std::cout << "With pointer: ";
    identify(c);
    std::cout << "With reference: ";
    identify(*c);
    delete c;

    // NULL pointer
    std::cout << "\n--- Test NULL Pointer ---" << std::endl;
    Base *nullPtr = NULL;
    std::cout << "Test with NULL pointer: ";
    identify(nullPtr);

    return 0;
}