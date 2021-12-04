//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_FLIGHT_H
#define PROJ_DE_AED_FLIGHT_H

#include <string>


class Flight {
private:
    int FlightNumber;
    std::string StartDate;// format dd/mm/yyyy
    std::string Duration; // format hours:minutes
    std::string Origin;
    std::string destiny;

};


#endif //PROJ_DE_AED_FLIGHT_H
