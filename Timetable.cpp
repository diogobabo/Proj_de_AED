//
// Created by Diogo Babo on 19/12/2021.
//

#include "Timetable.h"
#include <sstream>
#include <fstream>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
void Timetable::SplitString(std::string s, std::vector<std::string> &v, char c) {

    std::string temp = "";
    for (int i = 0; i < s.length(); ++i) {

        if (s[i] == c) {
            v.push_back(temp);
            temp = "";
        } else {
            temp.push_back(s[i]);
        }

    }
    v.push_back(temp);
}
bool Timetable::isNumber(const std::string &s) const {            //verifies if the string contains only numbers
    for(int x = 0; x<s.size();x++){

        if(isdigit(s[x]) == false)
            return false;

    }
    return true;
}
void Timetable::timetableMenu() {
    //displays the menu and verifies the user input
    bool flag = true;

    int number = 50;

    while (flag) {          //checks the input
        std::cout << "1) SEARCH BY AIRPORT" << std::endl << "2) SEARCH BY AIRPORT AND DESTINY" << std::endl << "3) SHOW ALL" << std::endl<< "0) BACK" << std::endl;

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

            if (number == 1 || number == 2 || number == 0|| number == 3) {
                flag = false;
            } else {
                std::system(CLEAR);
                std::cout << "Invalid input, please try again:" << std::endl;
            }
        }
        if(flag == false){
            if(number == 0){
                return;
            }
            else if(number == 1){
                searchByAirport();
                flag = true;
            }
            else if(number == 2){
                searchByDestiny();
                flag = true;
            }
            else if(number == 3){
                printAll();
                flag = true;
            }
        }
    }
}

Timetable::Timetable(std::string text) {
    std::fstream f;
    f.open(text);
    if(!f.is_open()){
        throw "cant open";
    }
    std::vector<std::string> v;
    std::string s,airportName,rest,rest1;

    while(std::getline(f,s)){
        rest = s.substr(s.find(':')+1);
        airportName = s.substr(0,s.find(':'));
        Airport p(airportName);
        SplitString(rest,v,',');
        for(auto sus : v){
            std::vector<std::string> v1;
            rest1 = sus.substr(sus.find('(')+1);
            rest1 = rest1.substr(0,rest1.length()-1);
            SplitString(rest1,v1,'-');
            Transport t(sus.substr(0,sus.find('(')),v1[0],v1[1],std::stoi(v1[2]));
            p.addTransport(t);
        }
        airportBst.insert(p);

    }
    f.close();
}

void Timetable::printAll() {
    airportBst.printTree();
}
void Timetable::getString(std::string& y){
    bool flag = true;
    while (flag) {
        std::string x;

        std::cin >> x;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::system(CLEAR);
            std::cout << "Invalid input, please try again: " << std::endl;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();

            flag = true;

        }
        else{
            flag = false;
            y = x;
            return;
        }
    }
}
void Timetable::searchByAirport() {
    std::cout << "AIRPORT: " << std::endl;
    std::string airport;
    getString(airport);
    Airport air = airportBst.find(Airport(airport));
    if(air == Airport()){
        std::cout << "CANT FIND AIRPORT"<<std::endl;
        return;
    }
    std::cout<< air << std::endl;
}

void Timetable::searchByDestiny() {
    std::cout << "AIRPORT: " << std::endl;
    std::string airport;
    getString(airport);
    Airport air = airportBst.find(Airport(airport));
    if(air == Airport()){
        std::cout << "CANT FIND AIRPORT"<<std::endl;
        return;
    }
    std::cout << "DESTINY: " << std::endl;
    std::string destiny;
    getString(destiny);
    air.findPrintTransport(Transport(destiny));

}
