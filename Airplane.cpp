//
// Created by Diogo Babo on 04/12/2021.
//

#include <algorithm>
#include <iostream>
#include "Airplane.h"

void Airplane::addFligth(const Flight flight) {
    flights.push_back(flight);
}

std::string Airplane::getPlate() const{
    return plate;
}

int Airplane::getSeats() const {
    return seats;
}

std::list<Flight> &Airplane::getFlights(){
    return flights;
}

Airplane::Airplane(std::string plate, std::string type, int seatsAvailable) {
    this->plate = plate;
    this-> type = type;
    this->seats = seatsAvailable;
}
Airplane::Airplane(std::string plate) {
    this->plate = plate;
}

std::string Airplane::getType() const {
    return type;
}

void Airplane::addMaintenance(const Maintenance maintenance) {
    if(maintenance.isDone()){
        this->maintenanceToDone.push_back(maintenance);
    }
    else
        this->maintenanceToBeDone.push(maintenance);
}

std::list<Maintenance> Airplane::getMaintenanceDone() const {
    return maintenanceToDone;
}

std::queue<Maintenance> Airplane::getMaintenanceNotDone() const {
    return maintenanceToBeDone;
}

bool Airplane::operator==(const Airplane &a) const {
    return plate == a.getPlate();
}

bool Airplane::operator<(const Airplane &a) const {
    return plate<a.getPlate();
}

void Airplane::setMaintenanceNotDone(std::queue<Maintenance> temp) {
    this->maintenanceToBeDone = temp;
}

std::ostream &operator<<(std::ostream &f, const Airplane &a) {
    f << "PLATE: " <<  a.getPlate() << " TYPE: " <<  a.getType() << " CAPACITY: " << a.getSeats();
    return f;
}


