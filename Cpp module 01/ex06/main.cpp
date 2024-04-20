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
	{
        if (levels[i] == level)
            complaint = i;
	}

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
		std::cout << "[WARNING]" << std::endl;
		cmp.complain("WARNING");
		std::cout << std::endl;
		break ;
	default:
		std::cout << DEFAULT_MSG << std::endl;
		break;
	}
}

int	main(int argc, char **argv)
{
	Harl cmp;

	if (argc != 2)
		return (1);	
	check_input(cmp, argv[1]);
	return (0);
}
