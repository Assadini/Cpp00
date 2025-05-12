#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include<iostream>
#include <iomanip>
class Contact{

    public:
            std::string firstname;
            std::string lastname;
            std::string nickname;
            std::string phonenumber;
            std::string darkestsecret;
   
        Contact();
        void setContact(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber, const std::string &darkestSecret);
        void displayContact() const;  
        void displayHeader(int index) const;
        std::string formatColumn(const std::string &str) const;
};
#endif