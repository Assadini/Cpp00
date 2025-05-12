#include "Contact.hpp"
#include "PhoneBook.hpp"

bool containsDigit(const std::string& s) {
    for (std::string::size_type i = 0; i < s.length(); i++) {
        if (std::isdigit(s[i])) {
            return true;
        }
    }
    return false;
}

// Fonction pour vérifier si une chaîne est numérique
bool isNumeric(const std::string& s) {
    for (std::string::size_type i = 0; i < s.length(); i++) {
        if (!std::isdigit(s[i]) && s[i] != '-' && s[i] != ' ') {
            return false;
        }
    }
    return true;
}
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return ""; // La chaîne ne contient que des espaces

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
void addContact(PhoneBook &phonebook){
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darkestsecret;
    Contact contact;

    std::cout << "Enter first name: ";
    std::getline(std::cin, firstname);
    if(trim(firstname)==""){
        std::cout << "first name is emty aborting\n";
        return;
    }
    std::cout<<"enter lastname:";
    std::getline(std::cin,lastname);
    if(trim(lastname)==""){
        std::cout << "first name is emty aborting\n";
        return;
    }
    std::cout<<"enter nickname:";
    std::getline(std::cin,nickname);
    if(trim(nickname)==""){
        std::cout << "first name is emty aborting\n";
        return;
    }
    std::cout<<"enter phone number:";
    std::getline(std::cin,phonenumber);
    if(trim(phonenumber)==""){
        std::cout << "first name is emty aborting\n";
        return;
    }
    std::cout<<"enter darkestsecret:";
    std::getline(std::cin,darkestsecret);
    if(trim(darkestsecret)=="" ){
        std::cout << "first name is emty aborting\n";
        return;
    }
    std::cout << phonebook.getCurrentSize()<<std::endl;
    contact.setContact(firstname,lastname,nickname,phonenumber,darkestsecret);
    phonebook.list[phonebook.getCurrentSize()]=contact;
    phonebook.incSize();
    std::cout << phonebook.getCurrentSize()<<std::endl;
    if(phonebook.Size<4){
        phonebook.Size++;
    }
}
#include "PhoneBook.hpp"
int main(int ac,char **av){
    PhoneBook phone;
    std::string choise;
    std::cout << "Welcome to your Phone Book, " ;
    while(1){
    std::cout << "Choose action:\n" << "([ADD] a contact," << "[SEARCH] for a contact," <<"[EXIT] your PhoneBook): ";
    std::getline(std::cin,choise);
    std::cout << std::endl;
    if(!choise.compare("ADD")){
        addContact(phone);
    }
    else if(!choise.compare("EXIT")){
        break;
    }
    else if(!choise.compare("SEARCH")){
        phone.search();
    }
    }
    return(0);
}
