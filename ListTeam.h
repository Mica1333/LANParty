#ifndef LISTTEAM_H
#define LISTTEAM_H
#include "Node.h"

class ListTeam {
private:
    Node *first;

public:
    ListTeam();
    ~ListTeam();

 //   ListTeam& operator==(const ListTeam&);
    void addNode(Node *node);
    void deleteFromList(Team& team);
    Node* getNode(int offset);

    Team& getMinFromList();
};

#endif