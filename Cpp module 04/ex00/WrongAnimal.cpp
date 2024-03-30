#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default const was called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal default destruc was called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy const was called" << std::endl;
    *this = other;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "*** WrongAnimal SOUND ***" << std::endl;
}

std::string    WrongAnimal::getType() const
{
    return (this->type);
}