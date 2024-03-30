#ifndef ANIMAL_HPP

#define ANIMAL_HPP

#include <iostream>
#include <ctime>
# include <cstdlib>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &other);
	Animal& operator=(const Animal &other);
    virtual void makeSound() const;
    std::string getType() const;
};

#endif