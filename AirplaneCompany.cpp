//
// Created by Diogo Babo on 05/12/2021.
//

#include "AirplaneCompany.h"
#include <iostream>
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

        }
        for(auto x : m){
            if(x.find('-') == std::string::npos){
                Maintenance M(x.substr(x.find('/')),x.substr(0,10));
                p.addMaintenance(M);
            }else{
                std::vector<std::string> s;
                std::string x;
                SplitString(x,s,'-');
                Maintenance M(s[0].substr(x.find('/')),s[0].substr(0,10),s[1]);
                p.addMaintenance(M);
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
    std::stringstream buffer;                             // Store contents in a std::string
    buffer << f.rdbuf();
    std::string contents = buffer.str();

    f.close();
    contents.pop_back();                                  // Remove last character


    std::ofstream fileOut( clientsfileTXT , std::ios::trunc); // Open for writing (while also clearing file)
    fileOut << contents;
    f.close();
}

void AirplaneCompany::writeAirplanesFile(std::string airplanesfileTXT) {
    std::fstream f;
    f.open(airplanesfileTXT, std::ofstream::out | std::ofstream::trunc);
    std::string flights;

    for(auto x : planes) {
        flights = "";
        if(x.getFlights().empty()){
            f << x.getType() << '-' << x.getPlate() << '-' << std::to_string(x.getSeats()) << '-' << flights << std::endl;
            continue;
        }
        for(auto y : x.getFlights()) {
            std::string id = std::to_string(y.getFlightID());
            while(id.size() < 4) {
                id.insert(0,"0");
            }
            flights = flights + id + ':';
        }
        flights.pop_back();
        f << x.getType() << '-' << x.getPlate() << '-' << std::to_string(x.getSeats()) << '-' << flights << std::endl;
    }
    std::stringstream buffer;                             // Store contents in a std::string
    buffer << f.rdbuf();
    std::string contents = buffer.str();

    f.close();
    contents.pop_back();                                  // Remove last character


    std::ofstream fileOut( airplanesfileTXT , std::ios::trunc); // Open for writing (while also clearing file)
    fileOut << contents;
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
    std::stringstream buffer;                             // Store contents in a std::string
    buffer << f.rdbuf();
    std::string contents = buffer.str();

    f.close();
    contents.pop_back();                                  // Remove last character


    std::ofstream fileOut( flightsTXT , std::ios::trunc); // Open for writing (while also clearing file)
    fileOut << contents;
    f.close();
}

void AirplaneCompany::dump() {
    writeClientsFile("clientes.txt");
    writeFlightsFile("flights.txt");
    writeAirplanesFile("airplanes.txt");
}

void AirplaneCompany::getOptions() {

}
