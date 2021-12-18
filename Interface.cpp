//
// Created by Diogo Babo on 15/12/2021.
//

#include <iostream>
#include <sstream>
#include "Interface.h"
#include "AirplaneCompany.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

bool Interface::isNumber(const std::string &s) const            //verifies if the string contains only numbers
{
    for(int x = 0; x<s.size();x++){

        if(isdigit(s[x]) == false)
            return false;

    }
    return true;
}

int Interface::menuCall() {
    //displays the menu and verifies the user input
    bool flag = true;

    int number = 50;

    while (flag) {          //checks the input
        std::cout << "Login as: " << std::endl;
        std::cout << "1) AIRPLANE COMPANY" << std::endl << "2) NEW CLIENT" << std::endl << "3) TIMETABLES PUBLIC TRANSPORTS" << std::endl << "4) ADMIN" << std::endl << "0) EXIT"<< std::endl;

        std::string x;

        std::cin >> x;

        if (std::cin.fail() || std::cin.peek() != '\n' || x.size() != 1 || !isNumber(x)) {
            std::system(CLEAR);
            std::cout << "Invalid input, please try again: " << std::endl;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();

            flag = true;

        } else {

            std::stringstream ss(x);

            ss >> number;

            if (number == 1 || number == 2 || number == 0 || number == 3|| number == 4) {
                flag = false;
            } else {
                std::system(CLEAR);
                std::cout << "Invalid input, please try again:" << std::endl;
            }
        }
    }

    return number;
}

void Interface::iniciate() {

    while(true){
        int flag = menuCall();
        if(flag == 0){
            break;
        }else if(flag ==1){
            TYPE = AIRPLANECOMPANY;
        }
        else if(flag ==2){
            TYPE = NEWCLIENT;
        }
        else if(flag ==3){
            TYPE = TIMETABLESPUBLIC;
        }
        else if(flag ==4){
            TYPE = ADMIN;
        } else
            break;
        login();
    }


}

void Interface::login() {

    if(TYPE == AIRPLANECOMPANY){
        loginAsCompany();
    }
    else if(TYPE == NEWCLIENT){

    }
    else if(TYPE == TIMETABLESPUBLIC){

    }
    else if(TYPE == ADMIN){

    }

}
void Interface::loginAsCompany(){
    try{
        AirplaneCompany company("airplanes.txt","clientes.txt");
        company.dump();
    }catch(...){
        std::cout << "DATA FILES MISSING" << std::endl;
        system("pause");
        exit(EXIT_FAILURE);
    }


}

void Interface::povoarVoos() {

}
