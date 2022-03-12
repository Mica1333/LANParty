#include "ListTeam.h"

ListTeam::ListTeam() {
    first = nullptr;
}

void ListTeam::addNode(Node *node) {
    if (first == nullptr) {
        first = node;
        return;
    }

    // Node *p = first;
    // while (p->next != nullptr) {
    //     p = p->next;
    // }

    // p->next = node;

    node->next = first;
    first = node;
}

void ListTeam::deleteFromList(Team& team) {
   
    Node *p = first;
    if (team == first->team) {
        Node *aux = first;
        first = first->next;
        aux->next = nullptr;
        delete aux;
    } else {
        while (p->next->team != team) {
            p = p->next;
        }
        
        Node *q = p->next;
        if (q->next == nullptr) {
            p->next = nullptr;
            // q->team.~Team();
            delete q;
        } 
        else {
            Node *t = q->next;
            p->next = t;
            q->next = nullptr;
            delete q;
        }      
    }

    
}

Node* ListTeam::getNode(int offset) {
    if (first == nullptr) {
        return first;
    }

    int count = 0;
    Node *p = first;
    while (count < offset) {
        p = p->next;
        count++;
    }
    return p;
}

ListTeam::~ListTeam() {
}

Team& ListTeam::getMinFromList() {
    Node *p = first->next;
    float minim = first->score;
    Node *aux = first;

    while (p != nullptr) {
        if (p->score < minim) {
            minim = p->score;
            aux = p;
        }
        p = p->next;
    }

    // cout << minim << "\n";

    return aux->team;
}