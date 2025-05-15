#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

// Constructor
PhoneBook::PhoneBook() : currentSize(0), Size(0) {}

// Increment the size of the phonebook
void PhoneBook::incSize() {
    if (Size < 4) {
        Size++;
    }
}

// Get the current size of the phonebook
int PhoneBook::getCurrentSize() const{
    return currentSize;
}

// Add a new contact to the phonebook
void PhoneBook::addContact(std::string firstName,std::string lastName,std::string nickname,std::string phoneNumber,std::string darkestSecret) {

    list[currentSize].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);

    currentSize = (currentSize + 1) % 4; // Overwrite the oldest contact if full
    incSize();
}

// Display the phonebook in a tabular format
void PhoneBook::displayPhoneBook() const {
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    for (int i = 0; i < Size; i++) {
        list[i].displayHeader(i + 1);
    }
    std::cout << "--------------------------------------------" << std::endl;
}

// Search for a contact by index
bool PhoneBook::search() const {
    if (Size == 0) {
        std::cout << "PhoneBook is empty. Add some contacts first!" << std::endl;
        return false;
    }

    int index;
    std::cout << "Enter the index of the contact to display: ";
    std::cin >> index;

    if (std::cin.fail() || index < 1 || index > Size) {
        std::cin.clear();
        std::cout << "Invalid index. Please try again." << std::endl;
        return false;
    }

    list[index - 1].displayContact();
    return true;
}