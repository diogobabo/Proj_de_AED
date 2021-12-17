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

std::list<Maintenance> Airplane::getMaintenance() {
    return maintenanceToDone;
}
Airplane::Airplane(std::string plate, std::string type, int seatsAvailable) {
    this->plate = plate;
    this-> type = type;
    this->seats = seatsAvailable;
}