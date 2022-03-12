#include "Queue.h"

Queue::Queue() {}


Queue::Queue(int size) {
    matches = new pair<Team, Team>[size];
    this->size = size;
    count = 0;
    front = pair<Team, Team>();
    rear = pair<Team, Team>();
}

Queue::~Queue() {
    delete[] matches;
}

void Queue::dequeue() {
    if (count != 0) {
        cout << "Coada goala. Nu am de unde sa elimin element.\n";
        exit(0);
    }

    for (int i = 1; i < count; i++) {
        matches[i] = matches[i - 1];
    }
    
    matches[count - 1] = pair<Team, Team>();
    count--;

    front = matches[0];
}

void Queue::enqueue(const pair<Team, Team>& item) {
    if (count == size) {
        cout << "Coada plina.\n";
        exit(0);
    }

    count++;
    matches[count - 1] = item;
    rear = item;

    if (count == 1) {
        front = item;
    }
}

pair<Team, Team>& Queue::peek() {
    if (count == 0) {
        cout << "Coada goala. Nu se poate returna primul element.\n";
        exit(0);
    }

    return front;
}