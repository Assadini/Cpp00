#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): currentSize(0),Size(0){}

void PhoneBook::displayPhoneBook(Contact &c){
    std::cout << "Fullname: "+c.firstname+" "+c.lastname+"\nNickname: "+c.nickname+"\nPhone Number: "+c.phonenumber+"\nDarkest secret: "+c.darkestsecret+"\n";
    
}
int PhoneBook::getCurrentSize(){
    return this->currentSize;
}
void PhoneBook::incSize(){
    if(currentSize<8-1)
    currentSize++;
    else{
        currentSize=0;
    }
}
bool isdigit(char i){
    if(!(i>='0' && i<='9'))
    return false;
    return true;
}
bool PhoneBook::search() const {
    std::cout << Size;
        for (int i = 0; i < Size; i++) {
            list[i].displayHeader(i + 1);
        }
        std::cout << "Enter the index of the contact you want to view: ";
        std::string input;
        std::getline(std::cin, input); // Utilise getline pour la saisie pour gérer EOF correctement
    
        // Vérification que l'entrée est numérique
        bool isNumeric = true;
        for (std::string::size_type i = 0; i < input.length(); i++) {
            if (!isdigit(input[i])) {
                isNumeric = false;
                return true;
            }
        }
        
        if (isNumeric) {
            int index = std::atoi(input.c_str()); // Conversion de la chaîne en entier
    
            if (index < 1 || index > Size)
            {
                std::cout << "Invalid index index" << std::endl;
                return true; 
            } else { 
                list[index - 1].displayContact();
                return true; 
            }
        } else {
            std::cout << "Invalid index" << std::endl;
        }
        return true; 
    }