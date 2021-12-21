//
// Created by oliveira on 16/12/2021.
//

#ifndef PROJ_DE_AED_TRANSPORT_H
#define PROJ_DE_AED_TRANSPORT_H
#include <string>

class Transport{
private:
    std::string type;
    std::string destiny;
    int distance;
    std::string time;
public:
    /**
       * Constructor of the class
       * @param destiny
       * @param type
       * @param time
       * @param distance
     **/
    Transport(std::string destiny,std::string type,std::string time, int distance);

    /**
       * Constructor of the class
       * @param destiny
     **/
    Transport(std::string destiny);

    /**
     * returns the type of the transport
     * @returns the type
     */
    std::string getType() const;

    /**
     * returns the destiny of the transport
     * @returns the destiny
     */
    std::string getDestiny()const;

    /**
     * sets the type for a transport
     * @param type
     */
    void setType(const std::string type);

    /**
    * sets the distance for a transport
    * @param distance
    */
    void setDistance(const int distance);

    /**
     * returns the distance of the transport
     * @returns the distance
     */
    int getDistance() const;

    /**
    * sets the time for a transport
    * @param time
    */
    void setTime(const std::string time);

    /**
     * returns the time of the transport
     * @returns the time
     */
    std::string getTime() const;

    /**
     * overloading of operator <
     * @param t1
     * @return bool
     **/
    bool operator<(const Transport &t1) const;

    /**
     * overloading of operator ==
     * @param t1
     * @return bool
     **/
    bool operator==(const Transport &t1) const;

    /**
     * overloading of operator <<
     * @param ostream f
     * @param p
     * @return a ostream
     **/
    friend std::ostream& operator<<(std::ostream &f, const Transport &p);
};
#endif //PROJ_DE_AED_TRANSPORT_H
