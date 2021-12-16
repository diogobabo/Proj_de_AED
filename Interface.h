//
// Created by Diogo Babo on 15/12/2021.
//

#ifndef PROJ_DE_AED_INTERFACE_H
#define PROJ_DE_AED_INTERFACE_H


class Interface {
private:
    enum EntryType {AIRPLANECOMPANY, NEWCLIENT, TIMETABLESPUBLIC, ADMIN};
    EntryType TYPE;
    void login();
    int menuCall();
    bool isNumber(const std::string &s) const;
    void povoarVoos();
public:
    void iniciate();
};


#endif //PROJ_DE_AED_INTERFACE_H
