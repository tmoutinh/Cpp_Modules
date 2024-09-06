#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <sstream>
// # include "A.hpp"
// # include "B.hpp"
// # include "C.hpp"

class Base 
{
    public:
        virtual ~Base();
};

void identify(Base* p);
void identify(Base& p);
Base* generate(void);

#endif