//
// Created by Diogo Babo on 05/12/2021.
//

#include "AirplaneCompany.h"
#include <iostream>
#include <algorithm>
#include <sstream>

AirplaneCompany::AirplaneCompany(std::string aiplanesfileTXT, std::string clientsfileTXT):aiplanesfile(),clientsfile() {
    aiplanesfile.open(aiplanesfileTXT);
    clientsfile.open(clientsfileTXT);
    if(!aiplanesfile.is_open()){
        throw "aiplanesfileTXT";
    }
    if(!clientsfile.is_open()){
        throw "clientsfileTXT";
    }
    std::string s;
    while(std::getline(clientsfile,s)){
        if(s == "/n"){
            continue;
        }
        Passenger p(s.substr(0,s.find(':')),s.substr(s.find(':')+1,s.length()-1));
        clients.push_back(p);
    }
    std::sort(clients.begin(),clients.end());
    std::fstream flightFile;
    flightFile.open("flights.txt");

    if(!flightFile.is_open()){
        throw "flightFile";
    }
    while(std::getline(flightFile,s)){
        if(s == "/n"){
            continue;
        }

        std::vector<std::string> flight,p;

        SplitString(s,flight,'-');
        SplitString(flight[5],p,',');

        Flight f(std::stoi(flight[0]),flight[1],flight[2],flight[3],flight[4],p);
        allFlights.push_back(f);

    }

    while(std::getline(aiplanesfile,s)){
        bool flag = true;
        if(s == "/n"){
            continue;
        }
        std::string type= s.substr(0,4);
        std::string plate= s.substr(5,4);
        std::string seats = s.substr(10,3);
        std::string rest = s.substr(14);
        Airplane p(plate,type,std::stoi(seats));
        if(rest.find('-') == std::string::npos)
            flag = false;
        std::string flights = rest.substr(0,rest.find('-'));
        std::string maintenances = rest.substr(rest.find('-')+1);
        std::vector<std::string> f,m;
        SplitString(flights,f,':');
        SplitString(maintenances,m,',');

        for(auto x :f){
            for(auto y: allFlights){
                if(std::stoi(x) == y.getFlightID())
                    p.addFligth(y);
            }

        }if(flag){


        for(auto x : m){

            if(x.find('-') == std::string::npos){
                Maintenance M(x.substr(x.find('/')).substr(1),x.substr(0,10));
                p.addMaintenance(M);
            }else{
                std::vector<std::string> s;
                SplitString(x,s,'-');
                Maintenance M(s[0].substr(x.find('/')).substr(1),s[0].substr(0,10),s[1]);
                p.addMaintenance(M);
            }
        }
    }
        planes.push_back(p);

    }
    aiplanesfile.close();
    clientsfile.close();
    flightFile.close();

}
void AirplaneCompany::SplitString(std::string s, std::vector<std::string> &v, char c) {

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

void AirplaneCompany::writeClientsFile(std::string clientsfileTXT) {
    std::fstream f;
    f.open(clientsfileTXT,std::ofstream::out | std::ofstream::trunc);
    for(auto x : clients) {
        std::string id = std::to_string(x.getId());
        while(id.size() < 4) {
            id.insert(0,"0");
        }
        f << id << ':' << x.getName() << std::endl;
    }
    f.close();
}

void AirplaneCompany::writeAirplanesFile(std::string airplanesfileTXT) {
    std::fstream f;
    f.open(airplanesfileTXT, std::ofstream::out | std::ofstream::trunc);
    std::string flights,mainNotDone,mainDone, mainTotal;

    for(auto x : planes) {
        flights = "";
        mainNotDone = "";
        mainDone = "";
        mainTotal = "";
        if(x.getFlights().empty()){
            f << x.getType() << '-' << x.getPlate() << '-' << std::to_string(x.getSeats()) << std::endl;
            continue;
        }
        for(auto y : x.getFlights()) {
            std::string id = std::to_string(y.getFlightID());
            while(id.size() < 4) {
                id.insert(0,"0");
            }
            flights = flights + id + ':';
        }
        for(auto z : x.getMaintenanceDone()) {
            mainDone += z.getMaintenanceInfo() + ',';
        }
        std::queue<Maintenance> temp = x.getMaintenanceNotDone();
        while(!temp.empty()) {
            mainNotDone += temp.front().getMaintenanceInfo() + ',';
            temp.pop();
        }
        if(mainDone.length() != 0) {
            mainDone.pop_back();
        }
        if(mainNotDone.length() != 0) {
            mainNotDone.pop_back();
        }
        flights.pop_back();
        if(mainNotDone.length() != 0 && mainDone.length() != 0) {
            f << x.getType() << '-' << x.getPlate() << '-' << std::to_string(x.getSeats()) << '-' << flights << '-' << mainNotDone << ',' << mainDone << std::endl;
        }
        if(mainNotDone.length() == 0 && mainDone.length() != 0) {
            f << x.getType() << '-' << x.getPlate() << '-' << std::to_string(x.getSeats()) << '-' << flights << '-' << mainDone << std::endl;
        }
        if(mainNotDone.length() != 0 && mainDone.length() == 0) {
            f << x.getType() << '-' << x.getPlate() << '-' << std::to_string(x.getSeats()) << '-' << flights << '-' << mainNotDone << std::endl;
        }
        if(mainNotDone.length() == 0 && mainDone.length() == 0) {
            f << x.getType() << '-' << x.getPlate() << '-' << std::to_string(x.getSeats()) << '-' << flights << std::endl;
        }
    }
    f.close();
}
void AirplaneCompany::writeFlightsFile(std::string flightsTXT) {
    std::fstream f;
    f.open(flightsTXT, std::ofstream::out | std::ofstream::trunc);
    for(auto x : allFlights) {
        std::string clients = "";
        std::string id = std::to_string(x.getFlightID());
        while(id.size() < 4) {
            id.insert(0,"0");
        }
        for(auto y : x.getPassengersId()) {
            std::string idPass = std::to_string(y);
            while(idPass.size() < 4) {
                idPass.insert(0,"0");
            }
            clients += idPass + ',';
        }
        clients.pop_back();
        std::string a =  id + '-' + x.getStartDate() + '-' + x.getDuration() + '-' + x.getOrigin() + '-' + x.getDestiny() + '-' + clients;
        f << a << std::endl;
    }
    f.close();
}

void AirplaneCompany::dump() {
    writeClientsFile("clientes.txt");
    writeFlightsFile("flights.txt");
    writeAirplanesFile("airplanes.txt");
}
bool AirplaneCompany::isNumber(const std::string &s) const            //verifies if the string contains only numbers
{
    for(int x = 0; x<s.size();x++){

        if(isdigit(s[x]) == false)
            return false;

    }
    return true;
}
void AirplaneCompany::getOptions() {
     bool flag = true;

    int number = 50;

    while (flag) {          //checks the input
        std::cout << "1) ADD AIRPLANE" << std::endl << "2) ADD NEW CLIENT" << std::endl << "3) BUY PLANE TICKET FOR CLIENT" << std::endl << "4) AIRPLANES INFO" << std::endl<< "5) AIRPLANES CHANGE" << std::endl << "0) BACK"<< std::endl;

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

            if (number == 1 || number == 2 || number == 0 || number == 3|| number == 4|| number == 5) {
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
                addPlane();
                flag = true;
            }
            else if(number == 2){
                addClient();
                flag = true;
            }
            else if(number == 3){

            }
            else if(number == 4){
                airplanesInfo();
                flag = true;
            }
            else if(number == 5){

            }
        }
    }
}

void AirplaneCompany::addClient() {
    bool flag = true;

    while(flag == true){

        std::system(CLEAR);
        std::cout << "CLIENT NAME:";
        std::string x;
        std::cin >> x;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::system(CLEAR);
            std::cout << "Invalid input, please try again: " << std::endl;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();

        }else{
            flag = false;
            Passenger p(clients.back().getId()+1,x);
            clients.push_back(p);
            std::cout << "CLIENT ADDED" << std::endl;
            return;
        }
    }
}

void AirplaneCompany::airplanesInfo() {
    bool flag;
    int x;
    std::cout << "1) CHECK FLIGHTS OF A AIRPLANE" << std::endl << "2) SHOW ALL FLIGHTS" << std::endl;
    std::cin >> x;
    while(!std::cin || x > 2) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> x;
    }
    if(x == 1) {
        bool found = false;
        std::string plate;
        std::cout << "TYPE THE PLATE OF THE PLANE" << std::endl;
        checkInputStringPlane(plate);
        for(auto x : planes) {
            if(x.getPlate() == plate) {
                found = true;
                for(auto y : x.getFlights()) {
                    std::cout << "Flight from "<< y.getOrigin() << " to " << y.getDestiny() << " on " << y.getStartDate() << " with the duration of " <<  y.getDuration() << " (hours:minutes)" << std::endl;
                }
            }
        }
        std::cout << '\n';
        if(!found) {
            std::cout << "There are no flights for that plane!" << std::endl;
        }
    }
    else if(x == 2) {
        for(auto x : planes) {
            for(auto y : x.getFlights()) {
                std::cout << "Flight from "<< y.getOrigin() << " to " << y.getDestiny() << " on " << y.getStartDate() << " with the duration of " <<  y.getDuration() << " (hours:minutes)" << std::endl;
            }
        }
    }
    return;
}

void AirplaneCompany::checkInputStringPlane(std::string &x) {
    std::cin >> x;
    while(std::cin.fail() || x.length() != 4 || isNumber(x)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> x;
    }
}

void AirplaneCompany::addPlane() {
    std::string plate,type;
    int seats;
    std::cout << "TYPE THE TYPE OF THE PLANE" << std::endl;
    checkInputStringPlane(type);
    std::cout << "TYPE THE PLATE OF THE PLANE" << std::endl;
    checkInputStringPlane(plate);
    std::cout << "TYPE THE NUMBER OF SEATS OF THE PLANE" << std::endl;
    std::cin >> seats;
    while(!std::cin || std::to_string(seats).size() != 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> seats;
    }
    Airplane plane(plate,type,seats);
    planes.push_back(plane);
    std::cout << "Plane added SUCCESSFULLY!" << std::endl;
    return;
}



