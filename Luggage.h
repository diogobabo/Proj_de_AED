//
// Created by Diogo Babo on 18/12/2021.
//

#ifndef PROJ_DE_AED_LUGGAGE_H
#define PROJ_DE_AED_LUGGAGE_H

class Luggage {
private:
    int fi;
    int numLuggage;
public:
    Luggage(int fi,int n);
    Luggage();
    int getNumLuggage() const;
    int getid() const;
    void setNumLuggage(const int numLuggage);
};


#endif //PROJ_DE_AED_LUGGAGE_H
