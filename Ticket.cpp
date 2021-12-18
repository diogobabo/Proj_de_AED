//
// Created by oliveira on 16/12/2021.
//

#include "Ticket.h"

void Ticket::setCheckIn() {
    this->checkin = true;
}

bool Ticket::getCheckIn() {
    return this->checkin;
}

void Ticket::setFlight(Flight voo) {
    this->voo = voo;
}

Flight Ticket::getFlight() {
    return this->voo;
}
