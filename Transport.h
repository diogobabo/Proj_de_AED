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
    Transport(std::string destiny,std::string type,std::string time, int distance);
    std::string getType();
    void setType(std::string type);
    void setDistance(int distance);
    int getDistance();
    void setTime(std::string time);
    std::string getTime();
    bool operator<(const Transport &t1) const;
    bool operator==(const Transport &t1) const;
    friend std::ostream& operator<<(std::ostream &f, const Transport &p);
};
#endif //PROJ_DE_AED_TRANSPORT_H
