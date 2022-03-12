#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>
#include "player.h"
using namespace std;

class Team {
private:
    string name;
    Player *players;
    int numPlayers;

public:
    Team();
    Team(string, int, ifstream&);
    ~Team();

    string getName() {
        return name;
    }

    Player* getPlayers() {
        return players;
    }

    int getNumPlayers() {
        return numPlayers;
    }

    float calculateScore();

    Team& operator=(const Team& team);
    bool operator==(const Team&);
    bool operator!=(const Team&);

};

#endif