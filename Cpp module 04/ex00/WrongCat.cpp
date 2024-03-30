#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default const was called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat default destruc was called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy const was called" << std::endl;
    *this = other;
}

WrongCat  &WrongCat::operator=(const WrongCat &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "eng: Meow Meow " << std::endl;
    std::cout << "pt: Miau Miau" << std::endl;
}