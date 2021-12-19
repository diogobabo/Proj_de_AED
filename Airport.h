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
    BST<Transport> transports = BST<Transport>(Transport("0","0","0",0));

public:
    Airport(std::string name);

    std::string getName()const;
    void setName(std::string name);
    BST<Transport>& getTransports();
    void addTransport(Transport t1);
    bool removeTransport(Transport t1);
    bool operator<(const Airport &p)const;
    bool operator==(const Airport &p)const;
    friend ostream& operator<<(ostream &f, const Airport &p);
    Airport();
};

#endif //PROJ_DE_AED_AIRPORT_H
