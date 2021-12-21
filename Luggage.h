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
    /**
    * Constructor of the class
    * @param fi: flight id
    * @param n: number of luggage
    **/
    Luggage(int fi,int n);

    /**
    * Default constructor of the class
    **/
    Luggage();

    /**
    * returns the number of luggage
    * @return nr of luggage
    **/
    int getNumLuggage() const;

    /**
    * returns the id of the flight
    * @return id
    **/
    int getid() const;

    /**
    * sets the number of luggage
    * @param numLuggage : nr of luggage
    **/
    void setNumLuggage(const int numLuggage);
};


#endif //PROJ_DE_AED_LUGGAGE_H
