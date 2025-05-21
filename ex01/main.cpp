#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::string str;
    PhoneBook my_phonebook;
    int nb_contact(0);

    do{
        std::cout << "Waiting instruction [ADD] [SEARCH] [EXIT]:";
        //std::getline(std::cin, str);
        if (!std::getline(std::cin, str))
            break;// reset le flag d'erreur EOF
        if (str == "ADD")
        {
            my_phonebook.add();
            nb_contact = my_phonebook.getIndex();
        }
        else if (str == "SEARCH")
            my_phonebook.search();
    }while (str != "EXIT");
}
