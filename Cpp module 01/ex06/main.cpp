#include "Harl.hpp"

void	check_input(Harl cmp, std::string level)
{
	int	complaint;

	complaint = -1;
	std::string levels[4] =
    {
        "DEBUG",
        "ERROR",
        "INFO",
        "WARNING"
    };
    for (int i = 0; i < 4; i++)
        if (levels[i] == level)
            complaint = i;

	switch (complaint)
	{
	case 0:
		std::cout << "[DEBUG]" << std::endl;
		cmp.complain("DEBUG");
		std::cout << std::endl;
	case 1:
		std::cout << "[ERROR]" << std::endl;
		cmp.complain("ERROR");
		std::cout << std::endl;
	case 2:
		std::cout << "[INFO]" << std::endl;
		cmp.complain("INFO");
		std::cout << std::endl;
	case 3:
		std::cout << "[DEBUG]" << std::endl;
		cmp.complain("DEBUG");
		std::cout << std::endl;
		break ;
	default:
		std::cout << DEFAULT_MSG << std::endl;
		break;
	}
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
		check_input(cmp, level);
	}
	return (0);
}
