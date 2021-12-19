//
// Created by Diogo Babo on 19/12/2021.
//

#include "Timetable.h"
#include <fstream>

void Timetable::SplitString(std::string s, std::vector<std::string> &v, char c) {

    std::string temp = "";
    for (int i = 0; i < s.length(); ++i) {

        if (s[i] == c) {
            v.push_back(temp);
            temp = "";
        } else {
            temp.push_back(s[i]);
        }

    }
    v.push_back(temp);
}

Timetable::Timetable(std::string text) {
    std::fstream f;
    f.open(text);
    if(!f.is_open()){
        throw "cant open";
    }
    std::vector<std::string> v;
    std::string s,airportName,rest,rest1;

    while(std::getline(f,s)){
        rest = s.substr(s.find(':')+1);
        airportName = s.substr(0,s.find(':'));
        Airport p(airportName);
        SplitString(rest,v,',');
        for(auto sus : v){
            std::vector<std::string> v1;
            rest1 = sus.substr(sus.find('(')+1);
            rest1 = rest1.substr(0,rest1.length()-1);
            SplitString(rest1,v1,'-');
            Transport t(sus.substr(0,sus.find('(')),v1[0],v1[1],std::stoi(v1[2]));
            p.addTransport(t);
        }
        airportBst.insert(p);

    }
    f.close();
}

void Timetable::print() {
    airportBst.printTree();
}
