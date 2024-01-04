#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _nbcontact = 0;
    return ;
}

PhoneBook::~PhoneBook()
{
    return ;
}

void    PhoneBook::add_contact()
{
    std::string fn, ln,nc,nb,sc;

    if (this->_nbcontact >= 7)
        this->_nbcontact = 0;
    std::cout << "Input first name" << std::endl;
    std::getline(std::cin,fn,'\n');
    std::cout << "Input last name" << std::endl;
    std::getline(std::cin,ln,'\n');
    std::cout << "Input nickname" << std::endl;
    std::getline(std::cin,nc,'\n');
    std::cout << "Input phone number" << std::endl;
    std::getline(std::cin,nb,'\n');
    std::cout << "Input darkest secret" << std::endl;
    std::getline(std::cin,sc,'\n');

    if (fn.size() < 1 || ln.size() < 1 || nc.size() < 1
     || nb.size() < 1 || sc.size() < 1)
    {
        std::cout << "All fields must be filled" << std::endl;
        return ;
    }

    this->_Contact_array[this->_nbcontact] = Contact(fn,ln,nc,nb,sc);
    this->_nbcontact += 1;
    std::cout << CLEAR_SCREEN;
    std::cout << "------ Contact Saves ------" << std::endl;
}

void    PhoneBook::_display_contacts()
{
    std::string field;

    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    for(int i = 0;i < 8; i++)
    {
		std::cout << std::setw(10) << (i + 1) << "|";
        field = this->_Contact_array[i].get_fname();
        std::cout << std::setw(10) << Contact::formatfield(field) << "|";
        field = this->_Contact_array[i].get_lname();
        std::cout << std::setw(10) << Contact::formatfield(field) << "|";
		field = this->_Contact_array[i].get_nick();
        std::cout << std::setw(10) << Contact::formatfield(field) << std::endl;
    }

}

void    PhoneBook::search_contacts()
{
    int index;

    this->_display_contacts();
    std::cout << "Select contact index: ";
    std::cin >> index;
    if ( (index - 1) >= 0 && (index - 1) < 8)
    {
        std::cout << CLEAR_SCREEN;
        std::cout << "Index :" << index << std::endl;
        this->_Contact_array[index - 1].display();
    }
    else
    {
        std::cout << "Invalid Index" << std::endl;
        return ;
    }
}
