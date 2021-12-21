//
// Created by oliveira on 16/12/2021.
//

#include "Transport.h"

std::string Transport::getType() const {
    return type;
}

void Transport::setType(const std::string type) {
    this->type=type;
}

int Transport::getDistance() const {
    return distance;
}

void Transport::setDistance(const int distance) {
    this->distance=distance;
}

void Transport::setTime(const std::string time) {
    this->time=time;
}

std::string Transport::getTime() const {
    return time;
}

bool Transport::operator<(const Transport &t1) const {
    if(destiny == t1.destiny) {
        if (type == t1.type) {
            if (distance == t1.distance) {
                return time < t1.time;
            }
            return distance < t1.distance;
        }
        return type < t1.type;
    }
    return destiny < t1.destiny;
}

Transport::Transport(std::string destiny, std::string type,  std::string time, int distance) {
    this->destiny = destiny;
    this->type=type;
    this->distance=distance;
    this->time=time;
}

bool Transport::operator==(const Transport &t1) const {
    if(type == t1.type && distance == t1.distance && time == t1.time && destiny == t1.destiny) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &f, const Transport &p) {
    std::string s = " distancing " + std::to_string(p.distance) + " km" +" to " + p.destiny + " by "+ p.type + " at "+p.time + " (hh:mm) ";
    f<<s;
    return f;
}

Transport::Transport(std::string destiny) {
    this->destiny = destiny;
}

std::string Transport::getDestiny() const{
    return destiny;
}
