//
// Created by Diogo Babo on 18/12/2021.
//

#include "Luggage.h"



Luggage::Luggage(int fi,int n) {
    this->fi = fi;
    this->numLuggage = n;
}
Luggage::Luggage() {
    this->fi = 0;
    this->numLuggage = 0;
}

int Luggage::getNumLuggage() const {
    return numLuggage;
}

void Luggage::setNumLuggage(const int numLuggage) {
    this->numLuggage=numLuggage;
}

int Luggage::getid() const {
    return fi;
}