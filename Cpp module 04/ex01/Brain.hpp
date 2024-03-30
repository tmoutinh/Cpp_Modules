#ifndef BRAIN_HPP

#define BRAIN_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    ~Brain();
    Brain(const Brain &other);
	Brain& operator=(const Brain &other);
};


#endif