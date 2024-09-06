#include "A.hpp"

A::A() 
{
}

A::A(const A& other) 
{
    *this = other;
}

A& A::operator=(const A& other) 
{
    if (this != &other) 
    {
    }
    return (*this);
}

A::~A() 
{
}