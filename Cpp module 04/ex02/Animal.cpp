#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default const was called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal default destruc was called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy const was called" << std::endl;
    *this = other;
}

Animal  &Animal::operator=(const Animal &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

std::string    Animal::getType() const
{
    return (this->type);
}