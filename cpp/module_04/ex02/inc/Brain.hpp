/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:33:47 by lumartin          #+#    #+#             */
/*   Updated: 2025/05/21 14:15:05 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain
{    
    private:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain &src);
        ~Brain();
        Brain &operator=(const Brain &src);
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string &idea);

};

#endif
