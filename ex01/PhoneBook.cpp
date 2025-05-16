#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : currentSize(0), Size(0) {}

void PhoneBook::incSize(){
    if(currentSize<7)
    currentSize++;
    else{
        currentSize=0;
    }
}

int PhoneBook::getCurrentSize() const{
    return currentSize;
}

void PhoneBook::addContact(std::string firstName,std::string lastName,std::string nickname,std::string phoneNumber,std::string darkestSecret) {

    list[currentSize].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    incSize();
    if(Size<8){
        Size++;
    }
}


void PhoneBook::displayPhoneBook() const {
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    for (int i = 0; i < Size; i++) {
        list[i].displayHeader(i + 1);
    }
    std::cout << "--------------------------------------------" << std::endl;
}

void PhoneBook::search() const{
    std::string indexInput;
    if (Size == 0) {
        std::cout << "PhoneBook is empty. Please add a contact first.\n";
        return;
    }
    displayPhoneBook();

    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, indexInput);

    if (indexInput.empty()) {
        std::cout << "Invalid index. Returning to menu.\n";
        return;
    }

    for (size_t i = 0; i < indexInput.length(); i++) {
        if (!std::isdigit(indexInput[i])) {
            std::cout << "Invalid index. Returning to menu.\n";
            return;
        }
    }

    int index = 0;
    for (size_t i = 0; i < indexInput.length(); i++) {
        index = index * 10 + (indexInput[i] - '0');
    }
    if (index <= 0 || index > Size) {
        std::cout << "Index out of range. Returning to menu.\n";
        return;
    }

    list[index - 1].displayContact();
}