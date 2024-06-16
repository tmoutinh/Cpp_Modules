#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) 
{
    this->name = name;
    this->grade = grade;
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
{
    if (this != &other) 
    {
        this->name = other.name;
        this->grade = other.grade;
    }
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other) 
    {
        this->name = other.name;
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() 
{
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

void    Bureaucrat::decreaseGrade()
{
    this->grade++;
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
void    Bureaucrat::signForm(Form &f)
{
    if (f.getSign())
    {
        std::cout << this->name << " is already signed!"<< std::endl;
        return ;
    }
    try
    {
        f.beSigned(*this);
        std::cout << this->name << " signs " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " cannot sign " << f.getName() << " because grade is too low" << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}

void    Bureaucrat::incrementGrade()
{
    this->grade--;
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream&   operator<< (std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (os);
}