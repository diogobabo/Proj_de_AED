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
    Transport(std::string destiny);
    std::string getType() const;
    std::string getDestiny()const;
    void setType(const std::string type);
    void setDistance(const int distance);
    int getDistance() const;
    void setTime(const std::string time);
    std::string getTime() const;
    bool operator<(const Transport &t1) const;
    bool operator==(const Transport &t1) const;
    friend std::ostream& operator<<(std::ostream &f, const Transport &p);
};
#endif //PROJ_DE_AED_TRANSPORT_H
