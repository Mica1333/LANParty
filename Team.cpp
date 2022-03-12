#include "Team.h"
#include <bits/stdc++.h>

Team::Team() {
    name = "";
    numPlayers = 0;
    players = nullptr;
}

Team::Team(string name, int numPlayers, ifstream& fin) {
    this->name = name;
    this->numPlayers = numPlayers;

    this->players = new Player[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        string firstName;
        string secondName;
        int points;

        string line;
        getline(fin, line);
        istringstream inputToParse(line);

        inputToParse >> firstName >> secondName >> points;

        // cout << firstName << " " << secondName << " " << points << "\n";

        players[i] = Player(firstName, secondName, points);
    }
}

float Team::calculateScore() {
    int sum = 0;
    for (int i = 0; i < numPlayers; i++) {
        sum += players[i].getPoints();
    }

    return (float) sum / numPlayers;
}

bool Team::operator==(const Team& team) {
    if (name != team.name) {
        return false;
    }

    if (numPlayers != team.numPlayers) {
        return false;
    }

    for (int i = 0; i < numPlayers; i++) {
        if (players[i] != team.players[i]) {
            return false;
        }
    }

    return true;
}

bool Team::operator!=(const Team& team) {
    return !(*this == team);
}
 
Team& Team::operator=(const Team& team) {
    name = team.name;
    numPlayers = team.numPlayers;
    players = new Player[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        players[i] = team.players[i];
    }
}

Team::~Team() {
    if (players != nullptr) {
        delete[] players;
    }
}
