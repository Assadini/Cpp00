#include <iostream>
#include <cctype>

int main(int ac,char **av)
{
    std::string str;
    
    if(ac==1)  
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
    }
    else
    {
        for(int i=1;i<ac;i++){
            str = av[i];
            for(size_t j=0;j < str.length();j++){
                str[j]=std::toupper(str[j]);
                std::cout<< str[j];
            }
        }
        std::cout<<std::endl;
    }
}
