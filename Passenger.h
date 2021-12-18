//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_PASSENGER_H
#define PROJ_DE_AED_PASSENGER_H


#include <string>

class Passenger {
private:
    int id;
    std::string name;
public:
    Passenger(std::string id,std::string name);
    Passenger(int id,std::string name);
    void setId(int id);
    int getId();
    void setName(std::string name);
    std::string getName();
    bool operator <(Passenger &p);
};


#endif //PROJ_DE_AED_PASSENGER_H
