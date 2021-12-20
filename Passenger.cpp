//
// Created by Diogo Babo on 04/12/2021.
//

#include "Passenger.h"


void Passenger::setName(std::string name) {
    this->name=name;
}

std::string Passenger::getName() const {
    return name;
}

int Passenger::getId() const {
    return id;
}

void Passenger::setId(const int id) {
    this->id = id;
}

Passenger::Passenger(std::string id, std::string name) {
    this->name = name;
    this->id = std::stoi(id);
}

bool Passenger::operator<(const Passenger &p) const {
    return this->id<p.getId();
}

Passenger::Passenger(int id, std::string name) {
    this->name = name;
    this->id = id;
}

bool Passenger::operator==(const Passenger &p) const {
    return this->id == p.getId();
}
Passenger::Passenger() {
    id = 0;
    name = "";
}

Luggage& Passenger::getLuggage(int fid) const {
    for(auto x:l){
        if(x.getid() == fid){
            return x;
        }
    }
    Luggage e(fid,0);
    return e;
}

void Passenger::addLuggage(const Luggage l) {
    this->l.push_back(l);
}

std::list<Luggage> &Passenger::getAllLuggage() {
    return l;
}

