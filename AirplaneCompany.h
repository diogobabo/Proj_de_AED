//
// Created by Diogo Babo on 05/12/2021.
//

#ifndef PROJ_DE_AED_AIRPLANECOMPANY_H
#define PROJ_DE_AED_AIRPLANECOMPANY_H


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
public:
    AirplaneCompany(std::fstream aiplanesfile,std::fstream clientsfile);
    AirplaneCompany(std::string aiplanesfileTXT,std::string clientsfileTXT);


};


#endif //PROJ_DE_AED_AIRPLANECOMPANY_H