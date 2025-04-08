/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:13:51 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/07 18:28:10 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

int main(void)
{
    PhoneBook phonebook = PhoneBook();
    std::string command, command_i;
    std::cout << "Welcome to the PhoneBook!" << std::endl;
    std::cout << "What do you want to do? (ADD, SEARCH, EXIT) ~ ";

    while (std::getline(std::cin, command_i))
    {
        command = trim(command_i);
        for (size_t i = 0; i < command.length(); ++i) {
            command[i] = std::toupper(command[i]);
        }
        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
        {
            if (phonebook.getCount() == 0)
            {
                std::cout << "No contacts in the phonebook." << std::endl;
            }
            else
            {
                phonebook.displayContacts();
            }
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting the PhoneBook. Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
        std::cout << "What you want to do? (ADD, SEARCH, EXIT) ~ ";
    }
    
}