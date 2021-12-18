//
// Created by Diogo Babo on 05/12/2021.
//

#include "AirplaneCompany.h"
#include <iostream>

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
        Passenger p(s.substr(0,s.find(':')),s.substr(s.find(':')+1,s.length()-1));
        clients.push_back(p);
    }
    std::fstream flightFile;
    flightFile.open("flights.txt");

    if(!flightFile.is_open()){
        throw "flightFile";
    }
    while(std::getline(flightFile,s)){

        std::vector<std::string> flight,p;

        SplitString(s,flight,'-');
        SplitString(flight[5],p,',');

        Flight f(std::stoi(flight[0]),flight[1],flight[2],flight[3],flight[4],p);
        allFlights.push_back(f);

    }

    while(std::getline(aiplanesfile,s)){
        std::string type= s.substr(0,4);
        std::string plate= s.substr(5,4);
        std::string seats = s.substr(10,3);
        std::string rest = s.substr(14);
        Airplane p(plate,type,std::stoi(seats));
        std::string flights = rest.substr(0,s.find('-'));
        std::string maintenances = rest.substr(s.find('-')+1);
        std::vector<std::string> f,m;
        SplitString(flights,f,':');
        SplitString(maintenances,m,',');

        for(auto x :f){
            for(auto y: allFlights){
                if(std::stoi(x) == y.getFlightID())
                    p.addFligth(y);
                break;
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
    f.open(clientsfileTXT, std::ios::out | std::ios::trunc);
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
    f.open(airplanesfileTXT, std::ios::out | std::ios::trunc);
    std::string flights,main;

    for(auto x : planes) {
        flights = " ";
        main = " ";
        for(auto y : x.getFlights()) {
            std::string id = std::to_string(y.getFlightID());
            while(id.size() < 4) {
                id.insert(0,"0");
            }
            flights = flights + id + ':';
        }
        for(auto z : x.getMaintenance()) {
            main += z.getDate() + ',';
        }
        main.pop_back();
        flights.pop_back();
        f << x.getType() << '-' << x.getPlate() << '-' << std::to_string(x.getSeats()) << '-' << flights << '-' << main;
    }
}
