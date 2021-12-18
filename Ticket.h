//
// Created by oliveira on 16/12/2021.
//

#ifndef PROJ_DE_AED_TICKET_H
#define PROJ_DE_AED_TICKET_H
#include "Flight.h"


class Ticket{
private:
    Flight voo;
    bool checkin = false;
public:
    void setCheckIn();
    bool getCheckIn();
    void setFlight(Flight voo);
    Flight getFlight();
};
#endif //PROJ_DE_AED_TICKET_H
