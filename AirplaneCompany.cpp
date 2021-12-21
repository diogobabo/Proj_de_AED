//
// Created by Diogo Babo on 05/12/2021.
//

#include "AirplaneCompany.h"
#include "InternalLuggage.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>

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
        std::string rest;
        if(s.length()<15){
            rest = s;
            Airplane p(plate,type,std::stoi(seats));
            planes.push_back(p);
            continue;
        }else
            rest = s.substr(14);
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
    std::fstream l;
    l.open("luggage.txt");
    if(!l.is_open()){
        throw "luggage";
    }

    while(std::getline(l,s)){
        if(s == "/n"){
            continue;
        }
        std::string rest = s.substr(s.find('-')+1);
        int pid = std::stoi(s.substr(0+1,s.find('-')));
        int fid = std::stoi(rest.substr(0,s.find(':')));
        int n = std::stoi(rest.substr(rest.find(':')+1));
        Luggage s(fid,n);
        for(auto &sus: clients){
            if(sus.getId() == pid){
                sus.addLuggage(s);
            }
        }
    }
    luggageLogistic();
    l.close();
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
        if(clients.length() == 0){
            std::string a =  id + '-' + x.getStartDate() + '-' + x.getDuration() + '-' + x.getOrigin() + '-' + x.getDestiny();
            f << a << std::endl;
            continue;
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
    writeBaggageFile("luggage.txt");
}
bool AirplaneCompany::isNumber(const std::string &s) const {            //verifies if the string contains only numbers
    for(int x = 0; x<s.size();x++){

        if(isdigit(s[x]) == false)
            return false;

    }
    return true;
}
void AirplaneCompany::getOptions() {
    bool flag = true;

    int number = 50;

    while (flag) {//checks the input
        std::cout << "1) ADD NEW CLIENT" << std::endl << "2) BUY PLANE TICKET FOR CLIENT" << std::endl << "3) AIRPLANES DATA" << std::endl<< "4) FLIGHT MANAGEMENT" << std::endl << "5) MAINTENANCE"<< std::endl<< "0) BACK"<< std::endl;

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
                addClient();
                flag = true;
            }
            else if(number == 2){
                buyTicket();
                flag = true;
            }
            else if(number == 3){
                airplaneData();
                flag = true;
            }
            else if(number == 4){
                flightData();
                flag = true;
            }
            else if(number == 5){
                maintenaceData();
                flag = true;
            }
            else if(number == 6){
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
bool AirplaneCompany::sortByDate(Flight &f1, Flight &f2) {
    return f1.getStartDate()<f2.getStartDate();
}
bool AirplaneCompany::sortByTime(Flight &f1, Flight &f2) {
    return f1.getDuration()<f2.getDuration();
}

void AirplaneCompany::airplanesInfo() {
    bool flag;
    int x;
    std::cout << "1) CHECK FLIGHTS OF AN AIRPLANE" << std::endl<< "2) CHECK A FLIGHT OF AN AIRPLANE" << std::endl << "3) SHOW ALL FLIGHTS" << std::endl;
    std::cin >> x;
    while(!std::cin || x > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> x;
    }
    if(x == 1) {
        luggageLogistic();
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
        bool found = false;
        std::string plate;
        std::cout << "TYPE THE PLATE OF THE PLANE" << std::endl;
        checkInputStringPlane(plate);
        int flight;
        std::cout << "TYPE THE FLIGHT OF THE PLANE" << std::endl;
        std::cin >> flight;
        while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please try again: " << std::endl;
            std::cin >> flight;
        }
        for(auto x : planes) {
            if(x.getPlate() == plate) {
                for( auto &sus : x.getFlights()){
                    if(sus.getFlightID() == flight){
                        std::cout << "Flight from "<< sus.getOrigin() << " to " << sus.getDestiny() << " on " << sus.getStartDate() << " with the duration of " <<  sus.getDuration() << " (hours:minutes)" << std::endl;
                        std::cout << "LUGGAGE LOGISTIC: need "<< std::to_string(int(ceil((sus.getl().size()/4.0)))) << " cars with stacks of 4 bags to transport the luggage to the airplane"<<std::endl;
                    }
                }
            }
        }
        std::cout << '\n';
        if(!found) {
            std::cout << "There are no flights for that plane!" << std::endl;
        }
    }
    else if(x == 3) {
        int x;
        std::cout << "1) SORT FLIGHTS BY DATE" << std::endl << "2) SORT FLIGHTS BY TIME" << std::endl << "3) SEARCH FLIGHTS BY ORIGIN" << std::endl << "4) SEARCH FLIGHTS BY DESTINY" << std::endl;
        std::cin >> x;
        while(!std::cin || x > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please try again: " << std::endl;
            std::cin >> x;
        }
        if(x == 1){
            std::sort(allFlights.begin(),allFlights.end(),sortByDate);
            showAllFlights();
        } else if (x==2){
            std::sort(allFlights.begin(),allFlights.end(),sortByTime);
            showAllFlights();
        } else if(x == 3) {
            bool found = false;
            std::string origin;
            std::cout << "TYPE THE ORIGIN" << std::endl;
            checkInputStringFlight(origin);
            for(auto x : allFlights) {
                if(x.getOrigin() == origin) {
                    found = true;
                    std::cout << "Flight from "<< x.getOrigin() << " to " << x.getDestiny() << " on " << x.getStartDate() << " with the duration of " <<  x.getDuration() << " (hours:minutes)" << std::endl;
                }
            }
            if(!found){
                std::cout << "COULD NOT FIND FLIGHT "<<std::endl;
            }
        } else if(x==4) {
            bool found = false;
            std::string destiny;
            std::cout << "TYPE THE DESTINY" << std::endl;
            checkInputStringFlight(destiny);
            for(auto x : allFlights) {
                if(x.getDestiny() == destiny) {
                    found = true;
                    std::cout << "Flight from "<< x.getOrigin() << " to " << x.getDestiny() << " on " << x.getStartDate() << " with the duration of " <<  x.getDuration() << " (hours:minutes)" << std::endl;
                }
            }
            if(!found){
                std::cout << "COULD NOT FIND FLIGHT "<<std::endl;
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

void AirplaneCompany::checkInputStringFlight(std::string &x) {
    std::cin >> x;
    while(std::cin.fail() || isNumber(x)) {
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
    for(auto it = planes.begin(); it != planes.end(); it++) {
        if(it->getPlate() == plate && it->getType() == type) {
            std::cout << "Couldn't add the plane, it already EXISTS!" << std::endl;
            return;
        }
    }
    Airplane plane(plate,type,seats);
    planes.push_back(plane);
    std::cout << "Plane added SUCCESSFULLY!" << std::endl;
    return;
}

void AirplaneCompany::removePlane() {
    bool found = false;
    std::string plate,type;
    std::cout << "TYPE THE TYPE OF THE PLANE" << std::endl;
    checkInputStringPlane(type);
    std::cout << "TYPE THE PLATE OF THE PLANE" << std::endl;
    checkInputStringPlane(plate);
    for(auto it = planes.begin(); it != planes.end(); it++) {
        if(it->getPlate() == plate && it->getType() == type) {
            found = true;
            it = planes.erase(it);
            break;
        }
    }
    if(found) {
        std::cout << "AIRPLANE REMOVED SUCCESSFULLY!" << std::endl;
    }
    if(!found) {
        std::cout << "COULDNT FIND THE AIRPLANE!" << std::endl;
    }
}

void AirplaneCompany::removeClient() {
    bool flag = true;
    int id;
    std::cout << "TYPE THE ID OF THE CLIENT YOU WANT TO REMOVE" << std::endl;
    std::cin >> id;
    while(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> id;
    }
    for(auto it = clients.begin(); it != clients.end(); it++) {
        if(it->getId() == id) {
            it = clients.erase(it);
            flag = false;
            break;
        }
    }
    if(flag){
        std::cout << "CLIENT DOES NOT EXIST" << std::endl;
    }
}

void AirplaneCompany::addFlight() {
    int max = INT_MIN;
    std::string origin;
    std::string destiny;
    std::string date;
    std::string duration;
    std::string plate;
    bool found = false;
    for(auto x : planes) {
        for(auto y : x.getFlights()) {
            if(y.getFlightID() > max) {
                max = y.getFlightID();
            }
        }
    }
    int id = max + 1;
    std::cout << "TYPE THE ORIGIN OF THE FLIGHT" << std::endl;
    checkInputStringFlight(origin);
    std::cout << "TYPE THE DESTINY OF THE FLIGHT" << std::endl;
    checkInputStringFlight(destiny);
    std::cout << "TYPE THE DATE OF THE DEPARTURE OF THE FLIGHT (yyyy:mm:dd:hh:mm)" << std::endl;
    checkInputStringFlight(date);
    std::cout << "TYPE THE DURATION OF THE FLIGHT (hh:mm)" << std::endl;
    checkInputStringFlight(duration);
    std::cout << "PLATE OF THE PLANE THAT IS RESPONSIBLE FOR THE FLIGHT" << std::endl;
    checkInputStringPlane(plate);
    std::vector<std::string>p;
    Flight f1(id, date, duration , origin , destiny,p);

    for(auto &x: planes) {
        if(x.getPlate() == plate) {
            found = true;
            x.addFligth(f1);
            break;
        }
    }
    if(found) {
        allFlights.push_back(f1);
    }
    std::cout << "FLIGHT ADDED SUCCESSFULLY!" << std::endl;
    if(!found) {
        std::cout << "THE PLANE REQUEST DOESNT EXIST!" << std::endl;
    }
}

void AirplaneCompany::removeFlight() {
    bool found = false;
    int id;
    std::string plate;
    std::cout << "TYPE THE ID OF THE FLIGHT" << std::endl;
    std::cin >> id;
    while(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> id;
    }
    std::cout << "PLATE OF THE PLANE THAT IS RESPONSIBLE FOR THE FLIGHT" << std::endl;
    checkInputStringPlane(plate);
    for(auto it = planes.begin(); it != planes.end(); it++) {
        if(it->getPlate() == plate) {
            for(auto jt = it->getFlights().begin(); jt != it->getFlights().end(); jt++) {
                if(jt->getFlightID() == id) {
                    jt = it->getFlights().erase(jt);
                    found = true;
                    break;
                }
            }
        }
    }
    if(!found) {
        std::cout << "THE REQUEST FLIGHT DOES NOT EXIST!" << std::endl;
        return;
    }
    for(auto it = allFlights.begin(); it != allFlights.end(); it++) {
        if(it->getFlightID() == id) {
            it = allFlights.erase(it);
            break;
        }
    }
    std::cout << "FLIGHT REMOVED SUCCESSFULLY!" << std::endl;
}

void AirplaneCompany::flightData() {
    bool found = false;
    int id;
    std::string plate;
    std::cout << "1) REMOVE FLIGHT" << std::endl<< "2) ADD FLIGHT"<< std::endl << "3) CHECK FLIGHTS"<< std::endl;
    std::cin >> id;
    while(!std::cin || id > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> id;
    }
    if(id == 1){
        removeFlight();
    }else if(id == 2){
        addFlight();
    } else if(id == 3) {
        airplanesInfo();
    }
}

void AirplaneCompany::buyTicket() {
    bool flag;
    int x;
    int numL;
    std::cout << "CLIENT ID :" << std::endl;
    std::cin >> x;
    if(std::cin.eof()){
        return;
    }
    while(!std::cin || x > 1000) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> x;
    }
    std::cout << "NUMBER OF BAGGAGES:" << std::endl;
    std::cin >> numL;
    while(!std::cin || x > 1000) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> numL;
    }
    std::string plate;
    std::cout << "PLATE OF THE PLANE THAT IS RESPONSIBLE FOR THE FLIGHT" << std::endl;
    checkInputStringPlane(plate);
    int y;
    std::cout << "FLIGHT ID :";
    std::cin >> y;
    if(std::cin.eof()){
        return;
    }
    while(!std::cin || y > 1000) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> y;
    }
    for(auto &it1 : clients ){
        if(it1.getId() == x){
            for(auto &it2 : planes){
                if(it2.getPlate() == plate){
                    for(auto &it3 : it2.getFlights()){
                        if(it3.getFlightID() == y){
                            Luggage l(y,numL);
                            for(auto it = it3.getPassengersId().begin(); it != it3.getPassengersId().end(); it++) {
                                if(*it == x) {
                                    if(numL <= 0) {
                                        return;
                                    }
                                    it1.addLuggage(l);
                                    return;
                                }
                            }
                            it1.addLuggage(l);
                            it3.addPassenger(it1);
                            std::find(allFlights.begin(),allFlights.end(),it3)->addPassenger(it1);
                            std::cout << "ADDED" << std::endl;
                            return;
                        }
                    }
                    std::cout << "COULDNT FIND A FLIGHT MATCHING THE PLATE" << std::endl;
                    return;
                }
            }
            std::cout << "COULDNT THE PLATE" << std::endl;
            return;
        }
    }
    std::cout << "COULDNT FIND THE CLIENT" << std::endl;
    return;

}

void AirplaneCompany::writeBaggageFile(std::string baggageTXT) {
    std::fstream f;
    std::string sizeLug;
    std::string idP,idF;
    int numL;
    f.open(baggageTXT, std::ofstream::out | std::ofstream::trunc);
    for(auto x : clients) {
        idP = std::to_string(x.getId());
        while(idP.size()<4){
            idP.insert(0,"0");
        }
        for(auto sus : x.getAllLuggage()){
            idF = std::to_string(sus.getid());
            while(idF.size()<4){
                idF.insert(0,"0");
            }
            f << idP << '-' << idF << ':' << sus.getNumLuggage() << std::endl;
        }

    }
    f.close();
}

void AirplaneCompany::airplaneData() {
    int id;
    std::cout << "1) ADD AIRPLANE" << std::endl << "2) REMOVE AIRPLANE" << std::endl << "3) AIRPLANES INFO" << std::endl << "4) SHOW ALL AIRPLANES" << std::endl;
    std::cin >> id;
    while(!std::cin || id > 4) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> id;
    }
    if(id == 1) {
        addPlane();
    }
    else if(id == 2) {
        removePlane();
    }
    else if(id == 3) {
        airplanesInfo();
    }
    else if(id == 4) {
        int x;
        std::cout << "1) SORT AIRPLANES BY PLATE" << std::endl << "2) SORT AIRPLANES BY TYPE" << std::endl << "3) SORT AIRPLANES BY CAPACITY" << std::endl;
        std::cin >> x;
        while(!std::cin || x > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please try again: " << std::endl;
            std::cin >> x;
        }
        if(x == 1){
            std::sort(planes.begin(),planes.end(), sortByPlate);
            showAirplanes();
        } else if(x == 2){
            std::sort(planes.begin(),planes.end(), sortByType);
            showAirplanes();
        }
        else if(x==3) {
            std::sort(planes.begin(), planes.end(),sortByCapacity);
            showAirplanes();
        }
    }
}

void AirplaneCompany::addMaintenance() {
    std::string type;
    std::string date;
    std::string plateP;
    bool found = false;
    std::cout << "TYPE OF MAINTENANCE (limpeza / manuntencao)" << std::endl;
    checkInputStringFlight(type);
    std::cout << "TIME OF THE MAINTENANCE" << std::endl;
    checkInputStringFlight(date);
    std::cout << "PLATE OF THE AIRPLANE" << std::endl;
    checkInputStringPlane(plateP);
    for(auto it = planes.begin(); it != planes.end(); it++) {
        if(it->getPlate() == plateP) {
            found = true;
            Maintenance main(type,date);
            it->addMaintenance(main);
        }
    }
    if(!found) {
        std::cout << "COULD NOT ADD THE MAINTENANCE TO THE AIRPLANE" << std::endl;
    }
    else {
        std::cout << "MAINTENANCE ADDED SUCCESSFULLY" << std::endl;
    }
}

void AirplaneCompany::doMaintenance() {
    std::string type;
    std::string date;
    std::string plateP;
    std::string name;
    bool found = false;
    std::cout << "TYPE OF MAINTENANCE" << std::endl;
    checkInputStringFlight(type);
    std::cout << "TIME OF THE MAINTENANCE (yyyy:mm:dd)" << std::endl;
    checkInputStringFlight(date);
    std::cout << "PLATE OF THE AIRPLANE" << std::endl;
    checkInputStringPlane(plateP);
    std::cout << "WHO IS GOING TO DO THE MAINTENACE?" << std::endl;
    checkInputStringFlight(name);
    for(auto it = planes.begin(); it != planes.end(); it++) {
        if(it->getPlate() == plateP) {
            std::queue<Maintenance> temp = it->getMaintenanceNotDone();
            std::queue<Maintenance> temp2;
            while(!temp.empty()) {
                if(temp.front().getDate() == date && temp.front().getType() == type) {
                    Maintenance m = temp.front();
                    m.setMaintenaceDone(name);
                    it->addMaintenance(m);
                    temp.pop();
                }
                else {
                    temp2.push(temp.front());
                    temp.pop();
                }
            }
            it->setMaintenanceNotDone(temp2);
        }
    }
}

void AirplaneCompany::maintenaceData() {
    int id;
    std::cout << "1) ADD A MAINTENANCE (TO BE DONE)" << std::endl << "2) COMPLETE A MAINTENANCE" << std::endl;
    std::cin >> id;
    while(!std::cin || id > 2) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again: " << std::endl;
        std::cin >> id;
    }
    if(id == 1) {
        addMaintenance();
    }
    else if(id == 2) {
        doMaintenance();
    }
}

void AirplaneCompany::showAirplanes() {
    for(auto x : planes) {
        std::cout << x << std::endl;
    }
}

bool AirplaneCompany::sortByPlate(Airplane &p1, Airplane &p2) {
    return p1.getPlate() < p2.getPlate();
}

bool AirplaneCompany::sortByType(Airplane &p1, Airplane &p2) {
    return p1.getType() < p2.getType();
}

bool AirplaneCompany::sortByCapacity(Airplane &p1, Airplane &p2) {
    return p1.getSeats() < p2.getSeats();
}

void AirplaneCompany::showAllFlights() {
    for(auto y : allFlights) {
        std::cout << "Flight from "<< y.getOrigin() << " to " << y.getDestiny() << " on " << y.getStartDate() << " with the duration of " <<  y.getDuration() << " (hours:minutes)" << std::endl;
    }
}

void AirplaneCompany::luggageLogistic() {

    for(auto &x :clients){

        for(auto &y : x.getAllLuggage()){

            for(int z = 0;z < y.getNumLuggage();z++){
                InternalLuggage l(x);
                for(auto &sus: allFlights){
                    if(sus.getFlightID() == y.getid()){
                        sus.addL(l);
                    }
                }
                for(auto &sus: planes){
                    for(auto &sus1: sus.getFlights()){
                        if(sus1.getFlightID() == y.getid()){
                            sus1.addL(l);
                        }
                    }
                }
            }

        }

    }

}



