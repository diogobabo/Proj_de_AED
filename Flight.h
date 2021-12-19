//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_FLIGHT_H
#define PROJ_DE_AED_FLIGHT_H

#include <string>
#include <list>
#include <vector>
#include "Passenger.h"

class Flight {
private:
    int FlightNumber;
    std::string StartDate;// format yyyy:mm:dd:hours:minutes
    std::string Duration; // format hours:minutes
    std::string Origin;
    std::string Destiny;
    std::list<int> passengersid;
public:
    Flight(int number,std::string StartDate,std::string Duration,std::string Origin,std::string destiny,std::vector<std::string> passengersid);
    void setDate(std::string date);
    void setDuration(std::string Duration);
    int getFlightID();
    std::string getDuration();
    std::string getOrigin();
    std::string getStartDate();
    std::string getDestiny();
    std::list<int> getPassengersId();
    bool operator <(Flight &f);
    bool operator ==(Flight &f);
};


#endif //PROJ_DE_AED_FLIGHT_H
