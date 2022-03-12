#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include "Team.h"
using namespace std;


 /* struct Echipa {
    string nume;
    int nr;

    Echipa() {

    }

    Echipa(string _nume, int _nr) {
        nume = _nume;
        nr = _nr;
    }
}; */


struct Node {
    // pentru distrugere trebuie apelat destructorul lui team si facuta legatatura nullptr
    Team team;
    struct Node *next;
    float score;

    Node() {
        team = Team();
        next = nullptr;
        score = 0;
    }

    Node(int numPlayers, string name, Node *_next, ifstream& fin) {
        team = Team(name, numPlayers, fin);
        next = _next;
        score = team.calculateScore();
    }
};

#endif