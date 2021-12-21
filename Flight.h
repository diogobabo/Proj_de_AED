//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_FLIGHT_H
#define PROJ_DE_AED_FLIGHT_H

#include <string>
#include <list>
#include <vector>
#include <stack>
#include "Passenger.h"
#include "InternalLuggage.h"

class Flight {
private:

    int FlightNumber;
    std::string StartDate;// format yyyy:mm:dd:hours:minutes
    std::string Duration; // format hours:minutes
    std::string Origin;
    std::string Destiny;
    std::list<std::stack<InternalLuggage>> order;
    std::list<int> passengersid;
public:
    /**
     * Constructor of the class
     * @param number: number of the flight
     * @param StartDate: date of departure
     * @param Origin: place of origin
     * @param destiny: place of destiny
     * @param passengersid: vector of the ids of the passengers
     **/
    Flight(int number,std::string StartDate,std::string Duration,std::string Origin,std::string destiny,std::vector<std::string> passengersid);

    /**
    * Constructor of the class
    * @param number: number of the flight
    **/
    Flight(int number);

    /**
     * sets the date of departure
     * @param date: the date
     */
    void setDate(const std::string date);

    /**
     * sets the duration of the flight
     * @param date: the date
     */
    void setDuration(const std::string Duration);

    /**
     * returns the id of the flight
     * @return: flight ID
     */
    int getFlightID() const;

    /**
     * returns the duration of the flight
     * @return: duration
     */
    std::string getDuration() const;

    /**
     * returns the origin of the flight
     * @return: origin
     */
    std::string getOrigin() const;

    /**
     * returns the start date of the flight
     * @return: date
     */
    std::string getStartDate() const;

    /**
     * returns the destiny of the flight
     * @return: destiny
     */
    std::string getDestiny() const;

    /**
     * returns the list of passengers
     * @return: passengers list
     */
    std::list<int> getPassengersId() const;

    /**
     * adds a passenger to the list of the passengers
     * @param: Passenger p
     */
    void addPassenger(const Passenger &p);

    /**
     * overloading of operator <
     * @param f
     * @return: a boolean
     **/
    bool operator <(Flight &f);

    /**
     * overloading of operator ==
     * @param: f
     * @return: bool if they are equal or not
     **/
    bool operator ==(const Flight &f) const;

    /**
     * adds a luggage to the stack of luggages'
     * @param: luggage
     */
    void addL(InternalLuggage luggage);

    /**
     * functions that returns a list of stacks of luggage
     * @return: order
     */
    std::list<std::stack<InternalLuggage>> getl();
};


#endif //PROJ_DE_AED_FLIGHT_H
