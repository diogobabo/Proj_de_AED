//
// Created by Diogo Babo on 15/12/2021.
//

#ifndef PROJ_DE_AED_INTERFACE_H
#define PROJ_DE_AED_INTERFACE_H


#include <vector>

class Interface {
private:
    enum EntryType {AIRPLANECOMPANY, TIMETABLESPUBLIC};
    EntryType TYPE;
    void login();
    int menuCall();
    bool isNumber(const std::string &s) const;
    void loginAsCompany();
    void loginTransports();
public:
    void iniciate();

};


#endif //PROJ_DE_AED_INTERFACE_H
