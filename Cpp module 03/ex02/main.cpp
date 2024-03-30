#include "FragTrap.hpp"

void usage(void)
{
        std::cout << "Usage: ./ex02 trap_name" << std::endl;
}

int main(int argc, char **argv)
{
        if (argc < 2)
                usage();
        FragTrap t1;
        FragTrap t2(argv[1]);
        FragTrap t3(t2);

        std::cout << "\n-------- Testing t3(t2) --------\n" << std::endl;
        t3.attack("something");
        t3.takeDamage(9);
        t3.beRepaired(5);
        t3.highFivesGuys();
        t3.takeDamage(100);
        t3.beRepaired(50);
}