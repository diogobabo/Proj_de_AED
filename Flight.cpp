//
// Created by Diogo Babo on 04/12/2021.
//

#include "Flight.h"

std::string Flight::getDuration() {
    return Duration;
}

void Flight::setDuration(std::string Duration) {
    this->Duration=Duration;
}

int Flight::getFlightID() {
    return FlightNumber;
}

std::string Flight::getOrigin() {
    return Origin;
}

std::string Flight::getStartDate() {
    return StartDate;
}

std::string Flight::getDestiny() {
    return Destiny;
}

void Flight::setDate(std::string date) {
    this->StartDate=date;
}