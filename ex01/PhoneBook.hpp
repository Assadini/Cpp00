#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact list[8];       // Array to store up to 4 contacts
    int currentSize;       // Index of the next contact to overwrite
    int Size;     // Total number of contacts in the phonebook

public:
    PhoneBook();

    // Methods
    void addContact(std::string firstName,std::string lastName,std::string nickname,std::string phoneNumber,std::string darkestSecret);
    int getCurrentSize() const;
    void incSize();
    void displayPhoneBook() const; // Removed unnecessary parameter
    bool search() const;
};

#endif