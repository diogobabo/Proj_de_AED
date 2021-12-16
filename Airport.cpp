//
// Created by oliveira on 16/12/2021.
//

#include "Airport.h"

std::string Airport::getName() {
    return name;
}

void Airport::setName(std::string name) {
    this->name=name;
}

BST<Transport> Airport::getTransports() {
    return transports;
}

void Airport::addTransport(Transport t1) {
    transports.insert(t1);
}

Airport::Airport(std::string name) {
    this->name=name;
}

bool Airport::removeTransport(Transport t1) {
    return transports.remove(t1);
}