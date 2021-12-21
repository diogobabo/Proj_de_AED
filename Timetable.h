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
    void SplitString(string s, vector<std::string> &v, char c);
    void searchByAirport();
    void searchByDestiny();
    void getString(std::string &y);
public:
    Timetable(std::string text);
    void timetableMenu();
    void printAll();


    bool isNumber(const string &s) const;



};


#endif //PROJ_DE_AED_TIMETABLE_H
