#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::complain(std::string level)
{
    void (Harl::*func[4])() = 
    {
        &Harl::debug,
        &Harl::error,
        &Harl::info,
        &Harl::warning
    };
    std::string levels[4] =
    {
        "DEBUG",
        "ERROR",
        "INFO",
        "WARNING"
    };
    for (int i = 0; i < 4; i++)
        if (levels[i] == level)
            (this->*func[i])();
}

void    Harl::debug()
{
    std::cout << DEBUG_MSG << std::endl;
}

void    Harl::info()
{
    std::cout << INFO_MSG << std::endl;
}

void    Harl::warning()
{
    std::cout << WARNING_MSG << std::endl;
}

void    Harl::error()
{
    std::cout << ERROR_MSG << std::endl;
}
