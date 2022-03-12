#include <iostream>
#include "ListTeam.h"
#include "Queue.h"
using namespace std;

#define NUM_TASKS 5

int calculateTeamsNum(int numTeams) {
    int teamsToDelete = 1;

    while (2 * teamsToDelete < numTeams) {
        // shiftare la dreapta a tuturor bitilor cu un singur bit <=> inmultire cu 2
        teamsToDelete <<= 1;
    }

    return numTeams - teamsToDelete;
}

void deleteTeams(int teamsToRemain, int& numTeams, ListTeam& teams) {
    for (int i = 0; i < teamsToRemain; i++) {
        teams.deleteFromList(teams.getMinFromList());
        numTeams--;
    }
} 

void do_tasks(ListTeam& teams, int& numTeams, int* tasks, ofstream& fout) {
    
    if (tasks[0] == true && tasks[1] == true) {
        deleteTeams(calculateTeamsNum(numTeams), numTeams, teams);

        // afisare  task2
        for (int i = 0; i < numTeams; i++) {
            if (i == numTeams - 1) {
                Node *p = teams.getNode(i);
                fout << p->team.getName();
            } else {
                Node *p = teams.getNode(i);
                fout << p->team.getName() << "\n";  
            }
        }
    } else {
        if (tasks[0] == true) {
            for (int i = 0; i < numTeams; i++) {
                if (i == numTeams - 1) {
                    Node *p = teams.getNode(i);
                    fout << p->team.getName();
                } else {
                    Node *p = teams.getNode(i);
                    fout << p->team.getName() << "\n";  
                }
            }
        }
    }
}


// m[10][10]                                    m = - - - - - - - - 
// *m[] pointer (care devine vector) de vectori
// **m

int main(int argc, char *argv[]) {
    // assert(freopen("d.in", "r", stdin) != NULL);
    // assert(freopen("r.out", "w", stdout) != NULL);
    ListTeam teams;
    int *tasks = new int[NUM_TASKS];

    ifstream cfile(argv[1]);
    ifstream fin(argv[2]);
    ofstream fout(argv[3]);

    for (int i = 0; i < NUM_TASKS; i++) {
        cfile >> tasks[i];
    }

    // citesc numarul de echipe
    int numTeams;
    fin >> numTeams;

    // citesc fiecare linie cu info despre echipa (numar jucatori, nume)
    // parsez linia
    // creez nod pe care il adaug in lista
    string line;
    getline(fin, line);
    for (int i = 0; i < numTeams; i++) {
        getline(fin, line);

        istringstream inputToParse(line);

        // imi iau numarul de playeri
        int numPlayers;
        inputToParse >> numPlayers;

        string teamName = "";
        string aux;
        while (inputToParse >> aux) {
            teamName += aux + " ";
        }
        
        teamName.erase(teamName.begin() + teamName.length() - 1);

        // aici avem numarul de playeri si numele echipei
        // trebuie sa cream vectorul de playeri

        Node *node = new Node(numPlayers, teamName, nullptr, fin);

        teams.addNode(node);
        
        getline(fin, line);
    }

    do_tasks(teams, numTeams, tasks, fout);

    Queue queueuOfMatches(numTeams / 2);

    cout << "Queue size: " << queueuOfMatches.getSize() << "\n\n";

    for (int i = 0; i < numTeams; i += 2) {
        cout << teams.getNode(i)->team.getName() << " VS. " << teams.getNode(i + 1)->team.getName() << "\n";
        queueuOfMatches.enqueue(pair<Team, Team>(teams.getNode(i)->team, teams.getNode(i + 1)->team));
    }

    cout << "-----------------------------------------------------------\n";


    for (int i = 0; i < queueuOfMatches.getCount(); i++) {
        cout << queueuOfMatches.getMatches()[i].first.getName() << " VS. " << queueuOfMatches.getMatches()[i].second.getName() << "\n";
    }

    cfile.close();
    fin.close();
    fout.close();
    delete[] tasks;
    return 0;
}