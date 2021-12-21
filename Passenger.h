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
    /**
   * Constructor of the class
   * @param id
   * @param name
   **/
    Passenger(std::string id,std::string name);

    /**
   * Constructor of the class
   * @param id
   * @param name
   **/
    Passenger(int id,std::string name);

    /**
   * Default constructor of the class
   **/
    Passenger();

    /**
   * sets the id of a passenger
   * @param id
   **/
    void setId(const int id);

    /**
   * function that returns the id of a passenger
   * @return id
   **/
    int getId() const;

    /**
   * sets the name of a passenger
   * @param name
   **/
    void setName(const std::string name);

    /**
   * function that returns the name of a passenger
   * @return name
   **/
    std::string getName() const;

    /**
     * overloading of operator <
     * @param p
     * @return bool
     **/
    bool operator <(const Passenger &p) const;

    /**
     * overloading of operator ==
     * @param p
     * @return bool if they are equal or not
     **/
    bool operator ==(const Passenger &p)const;

    /**
     * adds a luggage to the passengers luggage
     * @param l
     **/
    void addLuggage(const Luggage l);

    /**
     * returns the luggage of a passengers for a certain flight
     * @param fid
     * @return luggage
     **/
    Luggage& getLuggage(int fid) const;

    /**
     * returns a list of all luggages of a passenger
     * @return list of luggages
     **/
    std::list<Luggage>& getAllLuggage();
};


#endif //PROJ_DE_AED_PASSENGER_H
