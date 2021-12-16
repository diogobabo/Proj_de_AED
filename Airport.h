//
// Created by oliveira on 16/12/2021.
//

#ifndef PROJ_DE_AED_AIRPORT_H
#define PROJ_DE_AED_AIRPORT_H
#include <string>
#include "bst.h"
#include "Transport.h"

class Airport{
private:
    std::string name;
    BST<Transport> transports;

public:
    Airport(std::string name);
    std::string getName();
    void setName(std::string name);
    BST<Transport> getTransports();
    void addTransport(Transport t1);
    bool removeTransport(Transport t1);

};

#endif //PROJ_DE_AED_AIRPORT_H
