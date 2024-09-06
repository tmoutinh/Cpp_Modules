#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() 
{
}

/*------------------ Exercise Functions ------------------*/

Base* generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0) 
    {
        return (new A);
    } 
    else if (random == 1) 
    {
        return (new B);
    } 
    else 
    {
        return (new C);
    }
}


/*
Dynamic_cast is a type of castign that is used for safely converting pointers and references
to classes along the inheritance hierarchy. If the conversion is not valid at runtime it returns
nullptr for pointers and std::bad_cast exception for references.
*/

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A*\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B*\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C*\n";
	else
		std::cout << "Unknown pointer\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified A&\n";
		return ;
	}
	catch(const std::exception& e)
	{
		
	}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identified B&\n";
		return ;
	}
	catch(const std::exception& e)
	{
		
	}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identified C&\n";
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "Unknown type casting\n";
	}
	
}