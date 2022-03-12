#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    string firstName;
    string secondName;
    int points;

public:
    Player();
    Player(string&, string&, int&);
    Player(Player&);
    ~Player();
    Player& operator=(const Player&);
    bool operator==(const Player&);
    bool operator!=(const Player&);

    string getFirstName() {
        return firstName;
    }

    string getSecondName() {
        return secondName;
    }

    int getPoints() {
        return points;
    }
};

#endif