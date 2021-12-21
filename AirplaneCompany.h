//
// Created by Diogo Babo on 05/12/2021.
//

#ifndef PROJ_DE_AED_AIRPLANECOMPANY_H
#define PROJ_DE_AED_AIRPLANECOMPANY_H

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <vector>
#include <fstream>
#include "Airplane.h"
#include "Passenger.h"

class AirplaneCompany {
private:
    std::vector<Airplane> planes;
    std::vector<Passenger> clients;
    std::fstream aiplanesfile;
    std::fstream clientsfile;
    std::vector<Flight> allFlights;

    /**
        * iterates through the string s and divides it when it finds the char c, and adds it to the vector v
        * @param s
        * @param v
        * @param c
     **/
    void SplitString(std::string s, std::vector<std::string> &v,char c);

    /**
        * writes the clients and its details to its file
        * @param clientsfileTXT(file of the clients)
     **/
    void writeClientsFile(std::string clientsfileTXT);

    /**
        * writes the airplanes and its details to its file
        * @param airplanesfileTXT(file of the airplanes)
     **/
    void writeAirplanesFile(std::string airplanesfileTXT);

    /**
        * writes the flights to its file
        * @param flightsTXT(file of the flights)
     **/
    void writeFlightsFile(std::string flightsTXT);

    /**
        * checks if a string is a number
        * @param s(given string)
        * @return if s is a number or not
     **/
    bool isNumber(const std::string &s) const;

    /**
        * outputs all info regarding the flights and gives different options
     **/
    void airplanesInfo();

    /**
        * adds a client to the company
     **/
    void addClient();

    /**
        * adds a airplane to the company
     **/
    void addPlane();

    /**
        * checks if a string(input) passes all the tests
        * @param x(given string)
     **/
    void checkInputStringPlane(std::string &x);

    /**
        * checks if a string(input) passes all the tests
        * @param x(given string)
     **/
    void checkInputStringFlight(std::string &x);

    /**
        * removes a airplane from the company
     **/
    void removePlane();

    /**
        * removes a client from the company
     **/

    void removeClient();

    /**
        * adds a flight to the company
     **/
    void addFlight();

    /**
        * removes a flight from the company
     **/
    void removeFlight();

    /**
        * function to sort the flights by date of departure
        * @param f1,f2
        * @return boolean
     **/
    static bool sortByDate(Flight &f1,Flight &f2) ;

    /**
        * function to sort the flights by duration
        * @param f1,f2
        * @return boolean
     **/
    static bool sortByTime(Flight &f1,Flight &f2) ;

    /**
        * function to sort the airplanes by plate
        * @param p1,p2
        * @return boolean
     **/
    static bool sortByPlate(Airplane &p1, Airplane &p2);

    /**
        * function to sort the airplanes by type
        * @param p1,p2
        * @return boolean
     **/
    static bool sortByType(Airplane &p1, Airplane &p2);

    /**
        * function to sort the airplanes by capacity
        * @param p1,p2
        * @return boolean
     **/
    static bool sortByCapacity(Airplane &p1, Airplane &p2);

    /**
        * gives all options regarding flights(add,remove,check)
        **/
    void flightData();
    /**
        * option to buy a ticket to a certain flight, and asks for his lugagge as well
        **/
    void buyTicket();

    /**
        * writes the baggage and its details to its file
        * @param baggageTXT(file of the baggage)
     **/
    void writeBaggageFile(std::string baggageTXT);

    /**
       * gives all options regarding airplanes(add,remove,check)
       **/
    void airplaneData();

    /**
        * adds a maitenance to a airplane (giving the user free will to choose its type)
     **/
    void addMaintenance();

    /**
        * function to do a maintenance with the user giving the name of the person who did it
     **/
    void doMaintenance();

    /**
       * gives all options regarding maintenance(add,complete)
       **/
    void maintenaceData();

    /**
       * outputs all the airplanes
       **/
    void showAirplanes();

    /**
       * outputs all the flights
       **/
    void showAllFlights();
public:
    /**
        * Constructor of the class
        * @param aiplanesfileTXT: file of the airplanes
        * @param clientsfileTXT: file of the clients
        **/
    AirplaneCompany(std::string aiplanesfileTXT,std::string clientsfileTXT);
    /**
        * function that writes each info to their respective file (clients,airplanes,baggage,flights)
        **/

    void dump();
    /**
        * gives the different options for the AIRPLANE COMPANY submenu
        **/
    void getOptions();

    /**
        * does the logistics for the luggage for a flight
        **/
    void luggageLogistic();
};


#endif //PROJ_DE_AED_AIRPLANECOMPANY_H
