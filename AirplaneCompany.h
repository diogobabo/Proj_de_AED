//
// Created by Diogo Babo on 05/12/2021.
//

#ifndef PROJ_DE_AED_AIRPLANECOMPANY_H
#define PROJ_DE_AED_AIRPLANECOMPANY_H

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <vector>
#include <fstream>
#include "Airplane.h"
#include "Passenger.h"

class AirplaneCompany {
private:
    std::vector<Airplane> planes;
    std::vector<Passenger> clients;
    std::fstream aiplanesfile;
    std::fstream clientsfile;
    std::vector<Flight> allFlights;
    void SplitString(std::string s, std::vector<std::string> &v,char c);
    void writeClientsFile(std::string clientsfileTXT);
    void writeAirplanesFile(std::string airplanesfileTXT);
    void writeFlightsFile(std::string flightsTXT);
    bool isNumber(const std::string &s) const;
    void airplanesInfo();
    void addClient();
    void addPlane();
    void checkInputStringPlane(std::string &x);
    void checkInputStringFlight(std::string &x);
    void removePlane();
    void removeClient();
    void addFlight();
    void removeFlight();
    static bool sortByDate(Flight &f1,Flight &f2) ;
    static bool sortByTime(Flight &f1,Flight &f2) ;
    void flightData();
    void buyTicket();
    bool canBuyTicket(Airplane &a1);
    void writeBaggageFile(std::string baggageTXT);
public:
    AirplaneCompany(std::string aiplanesfileTXT,std::string clientsfileTXT);
    void dump();
    void getOptions();
};


#endif //PROJ_DE_AED_AIRPLANECOMPANY_H
