#include "Harl.hpp"

int	check_input(std::string level)
{
	if (level != "DEBUG" && level != "ERROR" && level != "INFO" && level != "WARNING")
	{
		std::cout << "Invalid command !" << std::endl;
		return (0);
	}
	return (1);
}

int	main(void)
{
	Harl cmp;
	std::string	level;

	while (1)
	{
		std::cout << "[DEBUG | ERROR | INFO | WARNING]"  << std::endl;
		std::cout << "Select level : ";
		std::getline(std::cin, level);
		if (std::cin.eof() || level.empty())
			break ;
		if (check_input(level))
			cmp.complain(level);
	}
	return (0);
}