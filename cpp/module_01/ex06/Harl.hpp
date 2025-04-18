/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:38:00 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/18 14:00:38 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
    std::string level;
    void debug();
    void info();
    void warning();
    void error();

public:
    Harl();
    ~Harl();
    void complain(std::string level);
};

#endif