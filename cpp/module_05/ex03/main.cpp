/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:19:55 by lumartin          #+#    #+#             */
/*   Updated: 2025/09/25 15:28:43 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/AForm.hpp"
#include "./inc/Intern.hpp"

int main(void)
{
	std::cout << "Intern test" << std::endl << std::endl;

	Intern Intern;
	AForm *robo_intern;

	robo_intern = Intern.makeForm("Nothing", "NOUP");
	robo_intern = Intern.makeForm("presidential request", "Roooooobot");

	delete robo_intern;
	
	return (0);
}
