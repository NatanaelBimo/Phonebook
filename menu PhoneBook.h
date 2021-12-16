#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using std::string;

class PhoneContact{
public:
    string name;
    string area_code;
    string mobile_number;

    PhoneContact(string input_name, string input_code, string input_number){
        PhoneContact::name = input_name;
        PhoneContact::area_code = input_code;
        PhoneContact::mobile_number = input_number;
    }

    string get_name(){
        return PhoneContact::name;
    }

    string get_code(){
        return PhoneContact::area_code;
    }

    string get_number(){
        return PhoneContact::mobile_number;
    }
};
//Function in data base system
class ContactDataBase{
public:
    std::ifstream input_contact;
    std::ofstream output_contact;
    string file_name;

    ContactDataBase(const char* file_name){
        ContactDataBase::file_name = file_name;
    }

    void addContactData(PhoneContact data){
        ContactDataBase::output_contact.open(ContactDataBase::file_name, std::ios_base::app);
        ContactDataBase::output_contact << data.get_name() << std::endl;
        ContactDataBase::output_contact << data.get_code() << std::endl;
        ContactDataBase::output_contact << data.get_number() << std::endl;
        ContactDataBase::output_contact.close();
    }

    void showContactData(PhoneContact data){
        string name;
        string area_code;
        string mobile_number;
        ContactDataBase::input_contact.open(ContactDataBase::file_name, std::ios::in);

        while(!ContactDataBase::input_contact.eof()){
            std::getline(ContactDataBase::input_contact, name);
            if((name == "")){
                continue;
            }
            std::getline(ContactDataBase::input_contact, area_code);
            std::getline(ContactDataBase::input_contact, mobile_number);
            std::cout << "==============================" << std::endl;
            std::cout << "                              " << std::endl;
            std::cout << name << std::endl;
            std::cout << "(+" << area_code << ") " << mobile_number << std::endl;
            std::cout << "                              " << std::endl;
        }
        std::cin.ignore(1,'\n');
        ContactDataBase::input_contact.close();
        std::cout << "==============================" << std::endl;
    }

    void editContactData(PhoneContact data){
        string name, mobile_number, area_code, line, temp;
        std::ofstream tempFile;
        ContactDataBase::input_contact.open(ContactDataBase::file_name);
        tempFile.open("Temp.txt", std::ios_base::app);

        std::cout << "+--------------------------------+" << std::endl;
        std::cout << "|          EDIT CONTACT          |" << std::endl;
        std::cout << "+--------------------------------+" << std::endl;
        std::cout << "Name              : ";
        std::cin >> name;

        while(!ContactDataBase::input_contact.eof()){
            std::getline(ContactDataBase::input_contact, line);

            if(line == name){
                std::cout << "New Name          : ";
                std::cin.ignore(1, '\n');
                std::getline(std::cin, name);
                line.replace(0, line.length(), name);
                tempFile << line << std::endl;
                std::getline(ContactDataBase::input_contact, line);
                std::cout << "Area Code         : " << line << std::endl;
                std::cout << "New Area Code     : ";
                std::getline(std::cin, area_code);
                if(name == "-"){
                    tempFile << line << std::endl;
                    goto update_number;
                }
                line.replace(0, line.length(), area_code);
                tempFile << line << std::endl;

                update_number:
                    std::getline(ContactDataBase::input_contact, line);
                    std::cout << "Mobile Number     : " << line << std::endl;
                    temp = line;
                    std::cout << "New Mobile Number : ";
                    std::getline(std::cin, mobile_number);
                    if(mobile_number == "-"){
                        goto next;
                    }
                    line.replace(0, line.length(), mobile_number);
            }
            next:
                tempFile << line << std::endl;
        }
        tempFile.close();
        ContactDataBase::input_contact.close();

        remove("Database.txt");
        rename("Temp.txt", "Database.txt");
    }

    void deleteContactData(PhoneContact data){
        string name, line, is_continue, temp;
        std::ofstream tempFile;
        ContactDataBase::input_contact.open(ContactDataBase::file_name);
        tempFile.open("Temp.txt", std::ios_base::app);

        std::cout << "+--------------------------------+" << std::endl;
        std::cout << "|         DELETE CONTACT         |" << std::endl;
        std::cout << "+--------------------------------+" << std::endl;
        std::cout << "Name              : ";
        std::cin >> name;

        while(!ContactDataBase::input_contact.eof()){
            std::getline(ContactDataBase::input_contact, line);
            temp = line;

            if(line == name){
                system("cls");

                std::cout << "Delete " << line << "?[y/n]: ";
                std::cin.ignore(1, '\n');
                std::getline(std::cin, is_continue);
                if((is_continue == "Y")|(is_continue == "y")){
                    std::getline(ContactDataBase::input_contact, line);
                    std::getline(ContactDataBase::input_contact, line);
                    std::getline(ContactDataBase::input_contact, line);
                    std::cout << "Delete successfully!" << std::endl;
                    goto label_next;
                }
                else if((is_continue == "N")|(is_continue == "n")){
                    tempFile << temp << std::endl;
                    goto label_next;
                }else{
                    std::cout << "Action aborted" << std:: endl;
                    tempFile << temp << std::endl;
                    goto label_next;
                }
            }
            label_next:
                tempFile << line << std::endl;
        }
        tempFile.close();
        ContactDataBase::input_contact.close();

        remove("Database.txt");
        rename("Temp.txt", "Database.txt");
    }

    void searchContactData(PhoneContact data){
        string name;
        string area_code;
        string mobile_number;
        string line;
        ContactDataBase::input_contact.open(ContactDataBase::file_name, std::ios::in);

        std::cout << "+--------------------------------+" << std::endl;
        std::cout << "|         SEARCH CONTACT         |" << std::endl;
        std::cout << "+--------------------------------+" << std::endl;
        std::cout << "Name              : ";
        std::cin >> name;
        system("cls");
        while(!ContactDataBase::input_contact.eof()){
            std::getline(ContactDataBase::input_contact, line);
            if((line == name)){
                std::getline(ContactDataBase::input_contact, area_code);
                std::getline(ContactDataBase::input_contact, mobile_number);
                std::cout << "==============================" << std::endl;
                std::cout << "                              " << std::endl;
                std::cout << name << std::endl;
                std::cout << "(+" << area_code << ") " << mobile_number << std::endl;
                std::cout << "                              " << std::endl;
            }
            
        }
        std::cin.ignore(1,'\n');
        ContactDataBase::input_contact.close();
        std::cout << "==============================" << std::endl; 
    }

    void searchDataByArea(PhoneContact data){
        string area_code;
        string name;
        string mobile_number;
        string line;
        ContactDataBase::input_contact.open(ContactDataBase::file_name, std::ios::in);

        std::cout << "+--------------------------------+" << std::endl;
        std::cout << "|     SEARCH CONTACT BY AREA     |" << std::endl;
        std::cout << "+--------------------------------+" << std::endl;
        std::cout << "Area Code         : ";
        std::cin >> area_code;
        system("cls");
        while(!ContactDataBase::input_contact.eof()){
            std::getline(ContactDataBase::input_contact, name);
            std::getline(ContactDataBase::input_contact, line);
            if((line == area_code)){
                std::getline(ContactDataBase::input_contact, mobile_number);
                std::cout << "==============================" << std::endl;
                std::cout << "                              " << std::endl;
                std::cout << name << std::endl;
                std::cout << "(+" << area_code << ") " << mobile_number << std::endl;
                std::cout << "                              " << std::endl;
            }
            
        }
        std::cin.ignore(1,'\n');
        ContactDataBase::input_contact.close(); 
    }
};

class Menu{
public:
    void addContact(){
        string name, mobile_number, area_code;
        system("cls");

        std::cout << "+--------------------------------+" << std::endl;
        std::cout << "|           ADD CONTACT          |" << std::endl;
        std::cout << "+--------------------------------+" << std::endl;

        std::cout << "Name              : ";
        std::cin.ignore(1, '\n');
        std::getline(std::cin, name);
        std::cout << "Area Code         : ";
        std::getline(std::cin, area_code);
        std::cout << "Mobile Number     : (+" << area_code << ") ";
        std::getline(std::cin, mobile_number);

        ContactDataBase database = ("Database.txt");
        PhoneContact contactdata = PhoneContact(name, area_code, mobile_number);
        database.addContactData(contactdata);
        std::cout << "Press any key to continue...";
        getch();
    }

    void showContact(){
        string name, mobile_number, area_code;
        system("cls");

        ContactDataBase database = ("Database.txt");
        PhoneContact contactdata = PhoneContact(name, area_code, mobile_number);
        database.showContactData(contactdata);
        getch();
    }

    void showAllContact(){
        string name, mobile_number, area_code;
        system("cls");

        ContactDataBase database = ("Database.txt");
        PhoneContact contactdata = PhoneContact(name, area_code, mobile_number);
        database.showContactData(contactdata);
        
    }

    void editContact(){
        string name, mobile_number, area_code;
        showAllContact();

        ContactDataBase database = ("Database.txt");
        PhoneContact contactdata = PhoneContact(name, area_code, mobile_number);
        database.editContactData(contactdata);
        std::cout << "Press any key to continue...";
        getch();
    }

    void deleteContact(){
        string name, mobile_number, area_code;
        showAllContact();

        ContactDataBase database = ("Database.txt");
        PhoneContact contactdata = PhoneContact(name, area_code, mobile_number);
        database.deleteContactData(contactdata);
        std::cout << "Press any key to continue...";
        getch();
    }

    void searchContact(){
        string name, mobile_number, area_code;
        system("cls");

        ContactDataBase database = ("Database.txt");
        PhoneContact contactdata = PhoneContact(name, area_code, mobile_number);
        database.searchContactData(contactdata);
        std::cout << "Press any key to continue...";
        getch();
    }

    void searchByArea(){
        string name, mobile_number, area_code;
        system("cls");

        ContactDataBase database = ("Database.txt");
        PhoneContact contactdata = PhoneContact(name, area_code, mobile_number);
        database.searchDataByArea(contactdata);
        std::cout << "Press any key to continue...";
        getch();
    }
};
