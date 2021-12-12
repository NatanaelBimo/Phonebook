#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "menu PhoneBook.h"

using std::string;

int main(){
    char action;
    string isContinue;

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
                addContact();
                break;
            case '2':
                showContact();
                break;
            case '3':
                searchContact();
                break;
            case '4':
                searchByArea();
                break;
            case '5':
                editContact();
                break;
            case '6':
                deleteContact();
                break;
            case '7':
                continue;
                break;
        }
        
    }while (action != '7');
    
    return 0;
}