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
    /**
   * Constructor of the class
   * @param type
   * @param date
   **/
    Maintenance(std::string Type,std::string Date);

    /**
   * Constructor of the class
   * @param type
   * @param date
   * @param Employee
   **/
    Maintenance(std::string Type,std::string Date,std::string Employee);

    /**
    * sets a maintenance that is not Done to Done, and also sets the employee who dit it
    * @param Employee
    **/
    void setMaintenaceDone(const std::string Employee);

    /**
    * returns if a maintenance is done or not
    * @return done
    **/
    bool isDone() const;

    /**
    * returns the date of the maintenance
    * @return date
    **/
    std::string getDate() const;

    /**
    * function that makes it easier to write the maintenance to the files
    * @return a string
    **/
    std::string getMaintenanceInfo()const;

    /**
    * returns the type of the maintenance
    * @return type
    **/
    std::string getType()const;
};


#endif //PROJ_DE_AED_MAINTENANCE_H
