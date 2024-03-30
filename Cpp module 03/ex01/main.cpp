#include "ScavTrap.hpp"

void usage(void)
{
	std::cout << "Usage: ./ex01 trap_name" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		usage();
		return (-1);
	}
	ScavTrap t1;
	ScavTrap t2(argv[1]);
	ScavTrap t3(t2);

	std::cout << "\n-------- Testing t3(t2) --------\n" << std::endl;
	t3.attack("John Cena");
	t3.takeDamage(9);
	t3.beRepaired(5);
	t3.guardGate();
	t3.takeDamage(100);
	t3.beRepaired(50);
	return 0;
}