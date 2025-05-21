/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:12:46 by jhervoch          #+#    #+#             */
/*   Updated: 2025/05/21 13:31:52 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>

PhoneBook::PhoneBook() : nb_contact(0), index(0) {}

int PhoneBook::getIndex(){
    return index;
}

void PhoneBook::add(){
    std::string mystr;
    Contact new_contact;

    std::cout << "Adding a new contact:" << std::endl;
    getData("Firstname:", mystr);
    new_contact.set_firstname(mystr);
    getData("Lastname:", mystr);
    new_contact.set_lastname(mystr);
    getData("Nickname:", mystr);
    new_contact.set_nickname(mystr);
    getData("Phone number:", mystr);
    new_contact.set_phonenumber(mystr);
    getData("Darkest secret:", mystr);
    new_contact.set_darkestsecret(mystr);
    contact_list[index] = new_contact;
    
    nb_contact++; 
    index = ++index % 8;
}

void PhoneBook::getData(std::string prompt, std::string& data){
    do{
    std::cout << prompt;
    if (!getline(std::cin, data))
        std::exit(0);
    } while(data.empty());
}

void PhoneBook::print_col(std::string str){
    if (str.size()>10)
    {
        str.resize(10);
        str[9] = '.';
    }
    std::cout << std::setw(10) << str << "|";
}

void PhoneBook::search(){
    std::ostringstream  str1;
    std::string         str_index;
    int                 int_index;
    int                 lim = nb_contact;
    ;

    if (nb_contact == 0)
    {
        std::cout << "There is no contact in the phonebook" << std::endl;
        return ;
    }
    if (nb_contact >= 8)
        lim = 8;
    std::cout << "     index|first name| last name|  nickname|" << std::endl;
    for (int i = 0; i < lim; ++i)
    {
        str1.str("");
        str1.clear();
        str1 << i;
        str_index = str1.str();
        print_col(str_index);
        print_col(contact_list[i].get_firstname());
        print_col(contact_list[i].get_lastname());
        print_col(contact_list[i].get_nickname());
        std::cout << std::endl;
    }
    std::cout << "Waiting index : ";
    if (!std::getline(std::cin, str_index))
        std::exit(0);
    std::istringstream iss(str_index);
    iss >> int_index;
    if (!iss.fail() && int_index >= 0 && int_index < lim)
    {
        std::cout << contact_list[int_index].get_firstname() << std::endl;
        std::cout << contact_list[int_index].get_lastname() << std::endl;
        std::cout << contact_list[int_index].get_nickname() << std::endl;
        std::cout << contact_list[int_index].get_phonenumber() << std::endl;
        std::cout << contact_list[int_index].get_darkestsecret() << std::endl;
    }else{
        std::cout << "Wrong index" << std::endl;
    }
}
