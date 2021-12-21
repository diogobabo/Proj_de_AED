//
// Created by Diogo Babo on 04/12/2021.
//

#include "Maintenance.h"

std::string Maintenance::getDate() const {
    return Date;
}

Maintenance::Maintenance(std::string Type, std::string Date) {
    this->Type = Type;
    this->Date = Date;
    this->Done = false;
}

Maintenance::Maintenance(std::string Type, std::string Date, std::string Employee) {
    this->Type = Type;
    this->Date = Date;
    this->Done = true;
    this->Employee = Employee;
}

bool Maintenance::isDone() const {
    return Done;
}
std::string Maintenance::getMaintenanceInfo() const {
    if(Done == false) {
        return(Date + '/' + Type);
    }
    else {
        return(Date + '/' + Type + '-' + Employee);
    }
}

std::string Maintenance::getType() const {
    return Type;
}

void Maintenance::setMaintenaceDone(std::string Employee) {
    this->Done = true;
    this->Employee = Employee;
}
