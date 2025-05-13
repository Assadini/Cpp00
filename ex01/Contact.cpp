#include "Contact.hpp"

Contact::Contact(){

}
void Contact::setContact(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber, const std::string &darkestSecret){
    this->firstname = firstName;
    this->lastname = lastName;
    this->nickname = nickname;
    this->phonenumber = phoneNumber;
    this->darkestsecret = darkestSecret;
}
void Contact::displayContact() const{
    std::cout << "First name: " << firstname << std::endl
    << "Last name: " << lastname << std::endl
    << "Nickname: " << nickname << std::endl
    << "Phone number: " << phonenumber << std::endl
    << "Darkest secret: " << darkestsecret << std::endl;
}
std::string Contact::formatColumn(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}
std::string intToString(int value) {
    std::stringstream numberInStrFormat;
    numberInStrFormat << value;
    return numberInStrFormat.str();
}
void Contact::displayHeader(int index) const {
    std::cout << "|" << formatColumn(intToString(index))
              << "|" << formatColumn(firstname)
              << "|" << formatColumn(lastname)
              << "|" << formatColumn(nickname)
              << "|" << std::endl;
}      
