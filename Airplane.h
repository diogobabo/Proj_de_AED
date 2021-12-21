//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_AIRPLANE_H
#define PROJ_DE_AED_AIRPLANE_H

#include <string>
#include <list>
#include <queue>
#include "Flight.h"
#include "Maintenance.h"

class Airplane {
private:
    std::string plate;
    std::string type;
    int seats;
    std::list<Flight> flights;
    std::queue<Maintenance> maintenanceToBeDone;
    std::list<Maintenance> maintenanceToDone;
public:
    /**
     * Constructor of the class
     * @param plate: plate of the airplane
     * @param type: plate of the airplane
     * @param seatsAvailable: nr of seats
     **/
    Airplane(std::string plate,std::string type,int seatsAvailable);

    /**
     * Constructor of the class
     * @param plate: plate of the airplane
     **/
    Airplane(std::string plate);

    /**
     * returns the plate of the airplane
     * @returns the plate
     */
    std::string getPlate()const;

    /**
     * sets the queue for maintenance to be done
     * @param temp: queue of maintenances
     **/
    void setMaintenanceNotDone(const std::queue<Maintenance> temp);

    /**
     * returns the number of seats
     * @returns the nr of seats of a plane
     */
    int getSeats() const;


    Flight getNextFlight();

    /**
     * adds a flight to the airplane
     * @param flight
     **/
    void addFligth(const Flight flight);

    /**
     * adds a maintenance to the airplane
     * @param maintenance
     **/
    void addMaintenance(const Maintenance maintenance);

    /**
     * returns the list of maintenances already Done
     * @returns list of maintenance
     */
    std::list<Maintenance> getMaintenanceDone() const;

    /**
     * returns the queue of maintenances not Done
     * @returns queue of maintenance
     */
    std::queue<Maintenance> getMaintenanceNotDone() const;

    /**
     * returns the list of flights of a airplane
     * @returns list of flights
     */
    std::list<Flight> &getFlights() ;

    /**
     * returns the type of a airplane
     * @returns the type
     */
    std::string getType() const;

    /**
     * overloading of operator ==
     * @param a
     * @return a boolean
     **/
    bool operator ==(const Airplane &a) const;

    /**
     * overloading of operator <
     * @param a
     * @return a boolean
     **/
    bool operator <(const Airplane &a) const;

    /**
     * overloading of operator <<
     * @param ostream f
     * @param a
     * @return a ostream
     **/
    friend std::ostream& operator<<(std::ostream &f, const Airplane &a);
};

#endif //PROJ_DE_AED_AIRPLANE_H
