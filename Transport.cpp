//
// Created by oliveira on 16/12/2021.
//

#include "Transport.h"

std::string Transport::getType() {
    return type;
}

void Transport::setType(std::string type) {
    this->type=type;
}

int Transport::getDistance() {
    return distance;
}

void Transport::setDistance(int distance) {
    this->distance=distance;
}

void Transport::setTime(std::string time) {
    this->time=time;
}

std::string Transport::getTime() {
    return time;
}

bool Transport::operator<(const Transport &t1) const {
    if(time == t1.time) {
        return distance < t1.distance;
    }
    return time < t1.time;
}

Transport::Transport(std::string destiny, std::string type,  std::string time, int distance) {
    this->destiny = destiny;
    this->type=type;
    this->distance=distance;
    this->time=time;
}

bool Transport::operator==(const Transport &t1) const {
    if(type == t1.type && distance == t1.distance && time == t1.time) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &f, const Transport &p) {
    std::string s = " distancing " + std::to_string(p.distance) + " km" +" to " + p.destiny + " by "+ p.type + " at "+p.time + " (hh:mm) ";
    f<<s;
    return f;
}
