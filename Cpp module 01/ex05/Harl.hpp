#ifndef _HARL_HPP
# define _HARL_HPP
# include <iostream>

#define DEBUG_MSG  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

class Harl
{
private:
    void    info();
    void    error();
    void    debug();
    void    warning();
public:
    Harl();
    ~Harl();
    void    complain(std::string level);
};

#endif
