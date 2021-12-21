//
// Created by Diogo Babo on 21/12/2021.
//

#ifndef PROJ_DE_AED_INTERNALLUGGAGE_H
#define PROJ_DE_AED_INTERNALLUGGAGE_H


#include "Luggage.h"
#include "Passenger.h"

class InternalLuggage {
private:
    Passenger &p;
public:
    InternalLuggage(Passenger &p);
    Passenger& getPassenger();
};


#endif //PROJ_DE_AED_INTERNALLUGGAGE_H
