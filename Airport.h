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
    /**
     * Constructor of the class
     * @param name: name of the airport
     **/
    Airport(std::string name);

    /**
     * returns the name of the airport
     * @returns returns the aiport name
     */
    std::string getName()const;

    /**
     * sets the name for the airport
     * @param name: name of the airport
     */
    void setName(const std::string name);

    /**
     * returns the BST of transports
     * @return the transports BST
     */
    BST<Transport>& getTransports();

    /**
     * adds a transport to the BST
     * @param t1
     **/
    void addTransport(const Transport t1);

    /**
     * removes a transport from the BST
     * @param t1
     * @return a boolean, depending on if it's possible to remove the transport or not
     **/
    bool removeTransport(const Transport t1);

    /**
     * overloading of operator <
     * @param p
     * @return a boolean
     **/
    bool operator<(const Airport &p)const;

    /**
     * overloading of operator ==
     * @param p
     * @return bool if they are equal or not
     **/

    bool operator==(const Airport &p)const;
    /**
     * overloading of operator <<
     * @param ostream f
     * @param Airport p
     * @return a ostream
     **/
    friend ostream& operator<<(ostream &f, const Airport &p);

    /**
     * default constructor for Airport
     **/
    Airport();
    void findPrintTransport(const Transport& transport)const;
};

#endif //PROJ_DE_AED_AIRPORT_H
