#include "Contact.hpp"
#include <iostream>
#include <iomanip>

// Default Constructor
Contact::Contact()
    : firstname(""), lastname(""), nickname(""), phonenumber(""), darkestsecret("") {}

// Setters
void Contact::setContact(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber, const std::string &darkestSecret) {
    this->firstname = firstName;
    this->lastname = lastName;
    this->nickname = nickname;
    this->phonenumber = phoneNumber;
    this->darkestsecret = darkestSecret;
}

// Getters
std::string Contact::getFirstName() const {
    return this->firstname;
}

std::string Contact::getLastName() const {
    return this->lastname;
}

std::string Contact::getNickname() const {
    return this->nickname;
}

std::string Contact::getPhoneNumber() const {
    return this->phonenumber;
}

std::string Contact::getDarkestSecret() const {
    return this->darkestsecret;
}

// Display full contact details
void Contact::displayContact() const {
    std::cout << "First name: " << firstname << std::endl
              << "Last name: " << lastname << std::endl
              << "Nickname: " << nickname << std::endl
              << "Phone number: " << phonenumber << std::endl
              << "Darkest secret: " << darkestsecret << std::endl;
}

// Format a column for display
std::string Contact::formatColumn(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}
std::string intToString(int value) {
    if (value == 0)
        return "0";

    std::string result;
    bool isNegative = (value < 0);
    if (isNegative)
        value = -value;

    while (value > 0) {
        result.insert(result.begin(), '0' + (value % 10));
        value /= 10;
    }

    if (isNegative)
        result.insert(result.begin(), '-');

    return result;
}
// Display contact header in a table format
void Contact::displayHeader(int index) const {
    std::cout << "|" << formatColumn(intToString(index))
              << "|" << formatColumn(firstname)
              << "|" << formatColumn(lastname)
              << "|" << formatColumn(nickname)
              << "|" << std::endl;
}