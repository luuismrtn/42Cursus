/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:37:30 by lumartin          #+#    #+#             */
/*   Updated: 2025/04/29 18:53:59 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replace(std::string &line, const std::string &s1, const std::string &s2)
{
    size_t pos = 0;
    if (s1.empty())
        return;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int argv, char **argc)
{
    if (argv != 4)
    {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        return 1;
    }

    std::string filename = argc[1];
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }

    std::string outfilename = filename + ".replace";
    std::ofstream outfile(outfilename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create output file" << std::endl;
        infile.close();
        return 1;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        replace(line, argc[2], argc[3]);
        outfile << line;
        if (!infile.eof())
            outfile << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
