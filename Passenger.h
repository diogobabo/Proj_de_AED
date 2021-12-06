//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_PASSENGER_H
#define PROJ_DE_AED_PASSENGER_H


#include <string>

class Passenger {
private:
    std::string name;
public:
    Passenger(std::string name);
    void setName(std::string name);
    std::string getName();
};


#endif //PROJ_DE_AED_PASSENGER_H
