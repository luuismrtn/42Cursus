/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:59:01 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/07 16:47:35 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;


    public:
        Fixed();
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &src);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif
