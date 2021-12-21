//
// Created by oliveira on 16/12/2021.
//

#include "Airport.h"

std::string Airport::getName() const{
    return name;
}

void Airport::setName(const std::string name) {
    this->name=name;
}

BST<Transport>& Airport::getTransports()  {
    return transports;
}

void Airport::addTransport(const Transport t1) {
    transports.insert(t1);
}

Airport::Airport(std::string name) {
    this->name=name;
}

bool Airport::removeTransport(const Transport t1) {
    return transports.remove(t1);
}

bool Airport::operator<(const Airport &p)const  {
    return name<p.getName();
}

bool Airport::operator==(const Airport &p) const {
    return name == p.getName();
}

Airport::Airport() {
    name = "";
}

ostream &operator<<(ostream &f, const Airport &p) {
    for(iteratorBST<Transport> it = p.transports.begin();it!=p.transports.end();it++){
        f<< "From: " << p.name << *it << endl;
    }
    return f;
}

void Airport::findPrintTransport(const Transport & transport) const {
    bool flag = true;
    for(iteratorBST<Transport> it = transports.begin();it!=transports.end();it++){
        if((*it).getDestiny() == transport.getDestiny()){
            std::cout<< "From: " << name << *it << endl;
            flag = false;
        }
    }
    if(flag){
        std::cout<< "COULD NOT FIND" << endl;
    }
    return;
}
