/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:11:28 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/10 11:20:42 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include "Contact.hpp"


class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
        int count;
        void displayContact(int index);

    public:
        PhoneBook();
        ~PhoneBook();
        void addContact();
        Contact getContact(int index);
        void displayContacts();
        int getCount() const { return count; }
};

#endif
