//
// Created by Diogo Babo on 04/12/2021.
//

#include "Airplane.h"

void Airplane::addFligth(Flight flight) {
    flights.push_back(flight);
}

std::string Airplane::getPlate() {
    return plate;
}

int Airplane::getSeats() {
    return seats;
}

std::list<Flight> Airplane::getFlights() {
    return flights;
}

Airplane::Airplane(std::string plate, std::string type, int seatsAvailable) {
    this->plate = plate;
    this-> type = type;
    this->seats = seatsAvailable;
}

std::string Airplane::getType() {
    return type;
}

void Airplane::addMaintenance(Maintenance maintenance) {
    if(maintenance.isDone()){
        this->maintenanceToDone.push_back(maintenance);
    }
    else
        this->maintenanceToBeDone.push(maintenance);
}

std::list<Maintenance> Airplane::getMaintenanceDone() {
    return maintenanceToDone;
}

std::queue<Maintenance> Airplane::getMaintenanceNotDone() {
    return maintenanceToBeDone;
}
