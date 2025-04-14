/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:11:22 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/10 11:20:52 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

Contact::Contact()
{
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
}

std::string Contact::formatField(const std::string field)
{
    std::string result;
    if (field.empty())
        return std::string(10, ' ');
    if (field.length() < 10)
        return std::string(10 - field.length(), ' ') + field;
    for (int i = 0; i < 10 && i < (int)field.length(); ++i)
    {
        result += field[i];
    }
    if (field.length() > 10)
        result = result.substr(0, 9) + ".";

    return result;
}

std::string Contact::toString_format()
{
    std::string contactInfo;

    std::string formattedFirstName = formatField(this->firstName);
    std::string formattedLastName = formatField(this->lastName);
    std::string formattedNickname = formatField(this->nickname);

    contactInfo += "|" + formattedFirstName + "|";
    contactInfo += formattedLastName + "|";
    contactInfo += formattedNickname + "|";

    return contactInfo;
}

std::string Contact::toString()
{
    std::string contactInfo;

    contactInfo += "First Name: " + this->firstName + "\n";
    contactInfo += "Last Name: " + this->lastName + "\n";
    contactInfo += "Nickname: " + this->nickname + "\n";
    contactInfo += "Phone Number: " + this->phoneNumber + "\n";
    contactInfo += "Darkest Secret: " + this->darkestSecret;

    return contactInfo;
}

