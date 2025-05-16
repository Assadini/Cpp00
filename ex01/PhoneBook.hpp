#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact list[8];
    int currentSize;
    int Size;

public:
    PhoneBook();


    void addContact(std::string firstName,std::string lastName,std::string nickname,std::string phoneNumber,std::string darkestSecret);
    int getCurrentSize() const;
    void incSize();
    void displayPhoneBook() const; 
    void search() const;
};

#endif