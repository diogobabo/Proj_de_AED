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
    std::string type;
    int seats;
    std::list<Flight> flights;
    std::queue<Maintenance> maintenanceToBeDone;
    std::list<Maintenance> maintenanceToDone;
public:
    Airplane(std::string plate,std::string type,int seatsAvailable);
    Airplane(std::string plate);
    std::string getPlate()const;
    void setMaintenanceNotDone(std::queue<Maintenance> temp);
    int getSeats();
    Flight getNextFlight();
    void addFligth(Flight flight);
    void addMaintenance(Maintenance maintenance);
    std::list<Maintenance> getMaintenanceDone();
    std::queue<Maintenance> getMaintenanceNotDone();
    std::list<Flight> &getFlights();
    std::string getType();
    bool operator ==(const Airplane &a) const;
    bool operator <(const Airplane &a) const;
};



#endif //PROJ_DE_AED_AIRPLANE_H
