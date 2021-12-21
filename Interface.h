//
// Created by Diogo Babo on 15/12/2021.
//

#ifndef PROJ_DE_AED_INTERFACE_H
#define PROJ_DE_AED_INTERFACE_H


#include <vector>

class Interface {
private:
    enum EntryType {
        AIRPLANECOMPANY, TIMETABLESPUBLIC
    };
    EntryType TYPE;

    /**
     * different options of login
     */
    void login();

    /**
     * displays the menu
     */
    int menuCall();

    /**
     * checks if a string is a number
     * @param: s
     * @return: bool true if it is a number false otherwise
     */
    bool isNumber(const std::string &s) const;

    /**
     * logs in a company
     */
    void loginAsCompany();

    /**
     * logs in as a transport timetable
     */
    void loginTransports();

    /**
    * display the menu
    */
    void showMenu();

    /**
     * displays the menu
     */

public:

    void iniciate();


};

#endif //PROJ_DE_AED_INTERFACE_H
