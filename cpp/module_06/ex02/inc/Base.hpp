/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:35:53 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/19 20:46:44 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cerrno>
#include <stdint.h>


class Base {
	public:
		virtual ~Base() = 0;
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
