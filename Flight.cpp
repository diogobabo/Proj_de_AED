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

int Flight::getFlightID() const{
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

bool Flight::operator<(Flight &f) {
    return getFlightID() <f.getFlightID();
}

bool Flight::operator==(const Flight &f) const {
    return getFlightID() == f.getFlightID();
}

Flight::Flight(int number, std::string StartDate, std::string Duration, std::string Origin, std::string destiny,std::vector<std::string> passengersid) {
    this->FlightNumber = number;
    this->StartDate = StartDate;
    this->Duration = Duration;
    this->Origin = Origin;
    this->Destiny = destiny;
    for(auto sus : passengersid){
        this->passengersid.push_back(std::stoi(sus));
    }
}

std::list<int> Flight::getPassengersId() {
    return passengersid;
}

Flight::Flight(int number) {
    this->FlightNumber = number;
}

