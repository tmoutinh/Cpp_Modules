#include <iostream>

int	main()
{
	std::string intro = "HI THIS IS BRAIN";
	/*This is the declaratio of a string reference*/
	std::string& strRef = intro;
	/*This is the reference to a pointer to a string*/
	std::string *strPtr = &intro;
	std::cout << "Memory addresses" << std::endl;
	std::cout << "string :" << &intro << std::endl;
	std::cout << "strRef :" << &strRef << std::endl;
	std::cout << "strPtr :" << strPtr << std::endl;

	std::cout << "Values" << std::endl;
	std::cout << "string :" << intro << std::endl;
	std::cout << "strRef :" << strRef << std::endl;
	std::cout << "strPtr :" << *strPtr << std::endl;
	return (0);
}
