#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   instance;
    std::string cmd;

    instance = PhoneBook();
    while (1)
    {
        std::cout << "Input command" << std::endl;
        std::cout << "[ADD] | [SEARCH] | [EXIT]" << std::endl;

        std::cin >> cmd;
        if (cmd == "ADD")
            instance.add_contact();
        if (cmd == "SEARCH")
            instance.search_contacts();
        if (cmd == "EXIT")
            break ;
        if (cmd.empty())
        {
            std::cout << "Invalid command\n> EXITED PHONEBOOK! <" << std::endl;
            break;
        }
        if (cmd != "ADD" && cmd != "SEARCH" && cmd != "EXIT")
            std::cout << "Invalid command" << std::endl;

    }
    return (0);
}
