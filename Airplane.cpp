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
    return seatsAvailable;
}

std::list<Flight> Airplane::getFlights() {
    return flights;
}

std::list<Maintenance> Airplane::getMaintenance() {
    return maintenanceToDone;
}