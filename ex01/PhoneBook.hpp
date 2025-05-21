#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook {

private:
    Contact contact_list[8];
    int nb_contact;
    int index;

    void print_col(std::string str);
    void exit();
    void getData(std::string, std::string&);

public:
    PhoneBook();
    int getIndex();
    void add();
    void search();
};

#endif
