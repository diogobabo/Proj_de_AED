//
// Created by Diogo Babo on 04/12/2021.
//

#ifndef PROJ_DE_AED_MAINTENANCE_H
#define PROJ_DE_AED_MAINTENANCE_H


#include <string>

class Maintenance {
private:
    std::string Type;
    std::string Date;//format yyyy:mm:dd
    std::string Employee;
    bool Done;//if maintenance is done , Done = true else done = false
public:
    Maintenance(std::string Type,std::string Date);
    Maintenance(std::string Type,std::string Date,std::string Employee);
    void setMaintenaceDone(const std::string Employee);
    bool isDone() const;
    std::string getDate() const;

    std::string getMaintenanceInfo()const;

    std::string getType()const;
};


#endif //PROJ_DE_AED_MAINTENANCE_H
