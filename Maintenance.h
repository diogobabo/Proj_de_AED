//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_MAINTENANCE_H
#define PROJ_DE_AED_MAINTENANCE_H


#include <string>

class Maintenance {
private:
    std::string Type;
    std::string Date;//format dd/mm/yyyy
    std::string Employee;
    bool Done;//if maintenance is done , Done = true else done = false
};


#endif //PROJ_DE_AED_MAINTENANCE_H
