#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "menu PhoneBook.h"

using std::string;

int main(){
    char action;
    Menu option;

    do{
        system("cls");
        std::cout << "+-----------------------------------------------------------------+" << std::endl;
        std::cout << "|                     WELCOME TO THE PHONEBOOK                    |" << std::endl;
        std::cout << "+-----+-------------------+---------------------------------------+" << std::endl;
        std::cout << "| 1   |   Add             |   Adding a new contact                |" << std::endl;
        std::cout << "| 2   |   Show All        |   Showing all contact                 |" << std::endl;
        std::cout << "| 3   |   Search          |   Find a contact by name              |" << std::endl;
        std::cout << "| 4   |   Search by Area  |   Display all contact from that area  |" << std::endl;
        std::cout << "| 5   |   Edit            |   Edit existing contact               |" << std::endl;
        std::cout << "| 6   |   Delete          |   Delete existing contact             |" << std::endl;
        std::cout << "| 7   |   Exit            |   Exit the app                        |" << std::endl;
        std::cout << "+-----------------------------------------------------------------+" << std::endl;
        std::cout << "Choose the action[1-7]: ";
        std::cin >> action;

        switch (action){
            case '1':
                option.addContact();
                break;
            case '2':
                option.showContact();
                break;
            case '3':
                option.searchContact();
                break;
            case '4':
                option.searchByArea();
                break;
            case '5':
                option.editContact();
                break;
            case '6':
                option.deleteContact();
                break;
            case '7':
                continue;
                break;
        }
        
    }while (action != '7');
    
    return 0;
}
