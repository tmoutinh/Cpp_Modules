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

std::string    _get_text(std::string txt)
{
    std::string data;
    std::cout << txt << std::endl;

    std::getline(std::cin, data);
    if (std::cin.eof())
		exit(0);
    size_t start = data.find_first_not_of(" \t\r\n");
    if (start == data.size())
	{
		std::cout << "ERROR: EMPTY FIELD.\n";
		return ("");
	}
	size_t end = data.find_last_not_of(" \t\r\n");
	data = data.substr(start, end - start + 1);
    return (data);
}

void    PhoneBook::add_contact()
{
    std::string fn, ln,nc,nb,sc;

    if (this->_nbcontact >= 7)
        this->_nbcontact = 0;
    fn = _get_text("Input first name");
    ln = _get_text("Input last name");
    nc = _get_text("Input nickname");
    nb = _get_text("Input phone number");
    sc = _get_text("Input darkest secret");

    if (fn.size() < 1 || ln.size() < 1 || nc.size() < 1
     || nb.size() < 1 || sc.size() < 1)
    {
        std::cout << "Contact not saved\n   All fields must be filled" << std::endl;
        sleep(2);
        return ;
    }
    this->_Contact_array[this->_nbcontact] = Contact(fn,ln,nc,nb,sc);
    this->_nbcontact += 1;
    system("clear");
    std::cout << "------ Contact Saved ------" << std::endl;
    sleep(2);
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
        system("clear");
        std::cout << "Index :" << index << std::endl;
        this->_Contact_array[index - 1].display();
    }
    else
        std::cout << "Invalid Index" << std::endl;
    sleep(2);
}
