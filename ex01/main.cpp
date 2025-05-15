#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>

// Helper function to trim whitespace
std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return ""; // String contains only spaces
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Add a contact to the phonebook
void addContact(PhoneBook &phonebook) {
    std::string firstname, lastname, nickname, phonenumber, darkestsecret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, firstname);
    if (trim(firstname).empty()) {
        std::cout << "First name is empty. Aborting.\n";
        return;
    }

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastname);
    if (trim(lastname).empty()) {
        std::cout << "Last name is empty. Aborting.\n";
        return;
    }

    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    if (trim(nickname).empty()) {
        std::cout << "Nickname is empty. Aborting.\n";
        return;
    }

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phonenumber);
    if (trim(phonenumber).empty()) {
        std::cout << "Phone number is empty. Aborting.\n";
        return;
    }

    // Manual check for digits
    for (size_t i = 0; i < phonenumber.length(); i++) {
        if (!std::isdigit(phonenumber[i])) {
            std::cout << "Phone number must contain only digits. Aborting.\n";
            return;
        }
    }

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestsecret);
    if (trim(darkestsecret).empty()) {
        std::cout << "Darkest secret is empty. Aborting.\n";
        return;
    }

    // Add the contact to the phonebook
    phonebook.addContact(firstname, lastname, nickname, phonenumber, darkestsecret);
}

// Main function
int main() {
    PhoneBook phonebook;
    std::string choice;

    std::cout << "Welcome to your Phone Book!\n";

    while (true) {
        std::cout << "Choose an action ([ADD], [SEARCH], [EXIT]): ";
        std::getline(std::cin, choice);

        if (std::cin.eof()) {
            std::cout << "\nExiting Phone Book. Goodbye!\n";
            break;
        }

        if (choice == "ADD") {
            addContact(phonebook);
        } else if (choice == "SEARCH") {
            phonebook.search();
        } else if (choice == "EXIT") {
            std::cout << "Exiting Phone Book. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}