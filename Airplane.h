//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_AIRPLANE_H
#define PROJ_DE_AED_AIRPLANE_H

#import <string>
#import <list>
#import <queue>
#include "Flight.h"
#include "Maintenance.h"

class Airplane {
private:
    std::string plate;
    int seatsAvailable;
    std::list<Flight> flights;
    std::queue<Maintenance> maintenanceToBeDone;
    std::list<Maintenance> maintenanceToDone;
public:

};


#endif //PROJ_DE_AED_AIRPLANE_H
