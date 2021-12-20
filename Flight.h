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
    Flight(int number);
    void setDate(const std::string date);
    void setDuration(const std::string Duration);
    int getFlightID() const;
    std::string getDuration() const;
    std::string getOrigin() const;
    std::string getStartDate() const;
    std::string getDestiny() const;
    std::list<int> getPassengersId() const;
    void addPassenger(const Passenger &p);
    bool operator <(Flight &f);
    bool operator ==(const Flight &f) const;
};


#endif //PROJ_DE_AED_FLIGHT_H
