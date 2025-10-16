/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:27:30 by lumartin          #+#    #+#             */
/*   Updated: 2025/10/16 16:53:32 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printAddress(T &element)
{
	std::cout << "Address: " << &element << ", Value: " << element << std::endl;
}

int main(void)
{
	std::cout << "\n\t--- Test string ---" << std::endl;
	std::string arr[] = {"Hola", "que", "tal?"};
	iter(arr, 3, printAddress<std::string>);

	std::cout << "\n\t--- Test int ---" << std::endl;
	int intArray[] = {1, 2, 3, 42};
	iter(intArray, 4, printAddress<const int>);

	std::cout << "\n\t--- Test float ---" << std::endl;
	float floatArray[] = {1.42f, 2.42f, 42.42f, 42424242.424242f, 0};
	iter(floatArray, 5, printAddress<float>);
	
	return 0;
}
