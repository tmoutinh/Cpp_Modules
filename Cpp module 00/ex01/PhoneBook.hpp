#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

/*************** -PhoneBookClass- *********************/

class   PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();

    void    add_contact();
    void    search_contacts();

private:
    int _nbcontact;
    static const int _max_contacts = 8;
    Contact _Contact_array[_max_contacts];

    void    _display_contacts();
};

#endif