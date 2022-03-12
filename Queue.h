#ifndef QUEUE_H
#define QUEUE_H
#include <bits/stdc++.h>
#include "Team.h"
using namespace std;

class Queue {
    pair<Team, Team> *matches;
    int size;
    int count;
    pair<Team, Team> front;
    pair<Team, Team> rear;

public:
    Queue();
    Queue(int);
    ~Queue();
    
    void dequeue();
    void enqueue(const pair<Team, Team>&);
    pair<Team, Team>& peek();

    pair<Team, Team>* getMatches() {
        return matches;
    }

    int getSize() {
        return size;
    }

    int getCount() {
        return count;
    }

    pair<Team, Team>& getFront() {
        return front;
    }

    pair<Team, Team>& getRear() {
        return rear;
    }
};

#endif