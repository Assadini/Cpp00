#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{

    public:
            Contact list[4];
            int currentSize;
            int Size;
               
            PhoneBook();
            addContact();
            int getCurrentSize();
            void incSize();
            void displayPhoneBook(Contact &phonebook); 
            bool search() const;       
};

#endif