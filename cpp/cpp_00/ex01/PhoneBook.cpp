/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:11:26 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/07 18:43:48 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    count = 0;
    index = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "\n\nPhoneBook has been deleted." << std::endl;
}

void PhoneBook::addContact()
{
    if (this->count >= 8)
    {
        std::cout << "The phonebook is full. Your oldest contact will be replaced." << std::endl;
    }

    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, firstName);
        if (firstName.empty())
            std::cout << "Field can't be empty, please try again." << std::endl;
    } while (firstName.empty());

    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, lastName);
        if (lastName.empty())
            std::cout << "Field can't be empty, please try again." << std::endl;
    } while (lastName.empty());

    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
        if (nickname.empty())
            std::cout << "Field can't be empty, please try again." << std::endl;
    } while (nickname.empty());

    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);
        if (phoneNumber.empty())
            std::cout << "Field can't be empty, please try again." << std::endl;
    } while (phoneNumber.empty());

    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, darkestSecret);
        if (darkestSecret.empty())
            std::cout << "Field can't be empty, please try again." << std::endl;
    } while (darkestSecret.empty());

    this->contacts[this->index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    this->index = (this->index + 1) % 8;
    this->count++;
    if (this->count > 8)
    {
        this->count = 8;
    }
    std::cout << "Contact added successfully!" << std::endl;
}

Contact PhoneBook::getContact(int index)
{
    if (index < 0 || index >= this->count)
    {
        std::cout << "Invalid index." << std::endl;
        return Contact();
    }
    return this->contacts[index];
}

void PhoneBook::displayContact(int index)
{
    Contact contact = getContact(index);
    std::cout << contact.toString() << std::endl;
};

void PhoneBook::displayContacts()
{
    std::string contactList;
    std::cout << "\n ------------------------------------------- \n";
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << "|----------|----------|----------|----------|\n";
    for (int i = 0; i < this->count; i++)
    {
        std::stringstream ss;
        ss << i + 1;
        contactList += "|         " + ss.str() + this->contacts[i].toString_format();
        contactList += "\n";
    }
    contactList += " ------------------------------------------- \n";
    std::cout << contactList << std::endl;

    std::cout << "Which contact number do you want to search? (1-8): ";
    std::string input;
    int index;
    while (std::getline(std::cin, input))
    {
        index = std::atoi(input.c_str());
        if (index > 0 && index <= this->count)
        {
            break;
        }
        std::cout << "Invalid index." << std::endl;
        std::cout << "Which contact number do you want to search? (1-8): ";
    }
    
    displayContact(index - 1);
}
