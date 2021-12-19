//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_PASSENGER_H
#define PROJ_DE_AED_PASSENGER_H


#include <string>
#include "Luggage.h"
#include <list>

class Passenger {
private:
    int id;
    std::string name;
    std::list<Luggage> l;
public:
    Passenger(std::string id,std::string name);
    Passenger(int id,std::string name);
    Passenger();
    void setId(int id);
    int getId() const;
    void setName(std::string name);
    std::string getName();
    bool operator <(Passenger &p);
    bool operator ==(const Passenger &p)const;
    void addLuggage(Luggage l);
    Luggage& getLuggage(int fid);
    std::list<Luggage>& getAllLuggage();
};


#endif //PROJ_DE_AED_PASSENGER_H
