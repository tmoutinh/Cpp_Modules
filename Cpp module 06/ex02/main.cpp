#include "Base.hpp"

void testBadIdentify(void)
{
	std::cout << "\n\t======== Testing bad identify ========\n\n";
	
	Base *pointer = NULL;
	Base reference;
	
	identify(pointer);
	identify(reference);
}

void testGoodIdentify(void)
{
	std::cout << "\n\t======== Testing cool identify ========\n\n";

	Base *random;
	random = generate();

	identify(random);
	identify(*random);
	delete random;
}

int main()
{
	std::srand(time(NULL));
	testGoodIdentify();
	testBadIdentify();
	return (0);
}