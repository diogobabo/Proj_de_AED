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
    void setId(const int id);
    int getId() const;
    void setName(const std::string name);
    std::string getName() const;
    bool operator <(const Passenger &p) const;
    bool operator ==(const Passenger &p)const;
    void addLuggage(const Luggage l);
    Luggage& getLuggage(int fid) const;
    std::list<Luggage>& getAllLuggage();
};


#endif //PROJ_DE_AED_PASSENGER_H
