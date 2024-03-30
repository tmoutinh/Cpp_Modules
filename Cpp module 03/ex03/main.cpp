#include "DiamondTrap.hpp"

void usage(void)
{
        std::cout << "Usage: ./ex02 trap_name" << std::endl;
}

int main(int argc, char **argv)
{
        if (argc < 2)
        {
                usage();
                return (0);
        }
        DiamondTrap t1;
        DiamondTrap t2(argv[1]);
        DiamondTrap t3(t2);

        std::cout << "\n-------- Testing t3(t2) --------\n" << std::endl;
        	t3.attack("something");
	t3.takeDamage(9);
	t3.beRepaired(5);
	t3.guardGate();
	t3.highFivesGuys();
	t3.whoAmI();
	t3.takeDamage(100);
	t3.beRepaired(50);
}