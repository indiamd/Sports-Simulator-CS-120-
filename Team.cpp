//
// Created by India Davis on 2/22/22.
//

#include "Team.h"
#include <iostream>
using namespace std;
using std::ostream;

Team::Team(){
    teamName= "Eagles";
    points= 0;
    gamesWon= 0;
    roster= {};
}

Team::Team(string name, int points, int numGames, vector<Athlete> roster){
    this->teamName= name;
    this->points= points;
    this->gamesWon= numGames;
    this->roster= roster;
}

//getters
string Team:: getTeamName() const{
    return teamName;
}

int Team:: getPoints() const{
    return points;
}

int Team::getGamesWon() const{
    return gamesWon;
}

vector<Athlete> Team::getRoster() const {
    return roster;
}

//setters
void Team:: setTeamName(string name){
    this->teamName = name;
}

void Team:: setPoints(int pts){
    points = pts;
}

void Team::setGamesWon(int won){
    gamesWon = won;
}

void Team:: addToRoster(Athlete athlete){
    roster.push_back(athlete);
}

void Team:: removeFromRoster(Athlete athlete){
    for (int i=0; i < roster.size(); i++) {
        if (roster[i].getLastName() == athlete.getLastName()){
            roster.erase(roster.begin() + i);
            --i;
        }
    }
}

void Team:: clearRoster(){
    roster.clear();
}

void Team::printRoster() {
    for (int i=0; i< roster.size(); i++){
        cout << roster[i].getLastName() << "   " << roster[i].getJerseyNum() << "   " << roster[i].getPointsScored() << " points scored" << endl;
    }
}