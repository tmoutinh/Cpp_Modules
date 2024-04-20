/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:20:55 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/04/20 11:20:56 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

void    _instructions(void)
{
	std::cout << "Welcome to your Personal PhoneBook Assistent\n\n"
			  << "Please insert one of the following commands: ⤵️\n"
			  << "• ADD: Save a new contact\n"
			  << "• SEARCH: Display a specific contact\n"
			  << "• EXIT: Exit Phonebook\n\n";
}

void	_header_msg(void)
{
	system("clear");
	std::cout << std::endl;
    std::cout << std::endl;
	std::cout << "██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗        ██████╗  ██████╗  ██████╗ ██╗  ██╗\n";
    std::cout << "██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝        ██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝\n";
    std::cout << "██████╔╝███████║██║   ██║██╔██╗ ██║█████╗          ██████╔╝██║   ██║██║   ██║█████╔╝ \n";
    std::cout << "██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝          ██╔══██╗██║   ██║██║   ██║██╔═██╗ \n";
    std::cout << "██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗\n";
    std::cout << "╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝\n";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
	_instructions();
}

void    _exec_cmd(PhoneBook *instance, std::string cmd)
{
    if (cmd == "ADD")
        instance->add_contact();
    if (cmd == "SEARCH")
        instance->search_contacts();
    if (cmd == "EXIT")
        exit(0);
    if (cmd != "ADD" && cmd != "SEARCH" && cmd != "EXIT")
    {
        system("clear");
        std::cout << "------ Invalid Command ------" << std::endl;
        sleep(2);
    }
}

std::string   _treat_cmd(std::string cmd)
{
    size_t start = cmd.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
	{
		std::cout << "ERROR: EMPTY FIELD.\n";
		sleep(2);
		std::cin.clear();
		system("clear");
		return (NULL);
	}
	size_t end = cmd.find_last_not_of(" \t\r\n");
	cmd = cmd.substr(start, end - start + 1);
    return (cmd);
}

int main(void)
{
    PhoneBook   instance;
    std::string cmd;

    instance = PhoneBook();
    while (1)
    {
        _header_msg();
        
        std::getline(std::cin, cmd);
        if (std::cin.eof())
			exit(0);
        if (!cmd.empty())
        {
            cmd = _treat_cmd(cmd);
            _exec_cmd(&instance, cmd);
        }
    }
    return (0);
}
