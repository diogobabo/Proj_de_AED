//
// Created by Diogo Babo on 19/12/2021.
//

#ifndef PROJ_DE_AED_TIMETABLE_H
#define PROJ_DE_AED_TIMETABLE_H


#include "bst.h"
#include "Airport.h"

class Timetable {
private:
    BST<Airport> airportBst = BST<Airport>(Airport());

    /**
        * iterates through the string s and divides it when it finds the char c, and adds it to the vector v
        * @param s
        * @param v
        * @param c
     **/
    void SplitString(string s, vector<std::string> &v, char c);

    /**
        * searchs for a transport for a specific airport
     **/
    void searchByAirport();

    /**
        * searchs for a transport for a specific destiny
     **/
    void searchByDestiny();

    /**
       * checks if the string is a valid input
       * @param y
    **/
    void getString(std::string &y);
public:
    /**
   * Constructor of the class
   * @param text
   **/
    Timetable(std::string text);

    /**
   * displays the menu of the transports
   **/
    void timetableMenu();

    /**
  * prints the entire BST
  **/
    void printAll();

    /**
    * checks if a string  is a number
     * @param s
     * @return true if it is a number false other wise
    **/
    bool isNumber(const string &s) const;



};


#endif //PROJ_DE_AED_TIMETABLE_H
