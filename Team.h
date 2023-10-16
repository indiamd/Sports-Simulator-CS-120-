//
// Created by India Davis on 2/22/22.
//

#ifndef M2OEP_LARGE_IDAVIS1_TEAM_H
#define M2OEP_LARGE_IDAVIS1_TEAM_H

#include "Athlete.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Team {

private:
    string teamName;
    int points;
    int gamesWon;
    vector<Athlete> roster;

public:

    //constructors
    Team();
    Team(string name, int points, int numGames, vector<Athlete> roster);

    //getters
    string getTeamName() const;
    int getPoints() const;
    int getGamesWon() const;
    vector<Athlete> getRoster() const;

    //setters
    void setTeamName(string name);
    void setPoints(int pts);
    void setGamesWon(int won);
    void addToRoster(Athlete athlete);
    void removeFromRoster(Athlete athlete);
    void clearRoster();
    void printRoster();

};


#endif //M2OEP_LARGE_IDAVIS1_TEAM_H
