//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_AIRPLANE_H
#define PROJ_DE_AED_AIRPLANE_H

#include <string>
#include <list>
#include <queue>
#include "Flight.h"
#include "Maintenance.h"

class Airplane {
private:
    std::string plate;
    int seatsAvailable;
    std::list<Flight> flights;
    std::queue<Maintenance> maintenanceToBeDone;
    std::list<Maintenance> maintenanceToDone;
public:
    Airplane(std::string plate);
    std::string getPlate();
    int getSeats();
    Flight getNextFlight();
    void addFligth(Flight flight);
    void addMaintenance(Maintenance maintenance);
    std::list<Maintenance> getMaintenance();
    std::list<Flight> getFlights();
    Flight getLastFlights();


};



#endif //PROJ_DE_AED_AIRPLANE_H
