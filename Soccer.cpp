//
// Created by India Davis on 2/22/22.
//

#include "Soccer.h"

Soccer::Soccer(){
    gameLength = 80;
    team1Score = 0;
    team2Score = 0;
    yellowCards = 0;
    redCards = 0;
}

Soccer:: Soccer(int length, int t1, int t2, int yellow, int red, bool pk){
    gameLength = length;
    team1Score = t1;
    team2Score = t2;
    yellowCards = yellow;
    redCards = red;
    pks= pk;
}

//getters
int Soccer:: getYellowCards(){
    return yellowCards;
}

int Soccer:: getRedCards(){
    return redCards;
}

bool Soccer:: getPks(){
    return pks;
}


//setters
void Soccer:: setYellowCards(int yellow){
    yellowCards= yellow;
}

void Soccer:: setRedCards(int red){
    redCards= red;
}

void Soccer:: setPks(bool pk){
    pks= pk;
}

void Soccer::team1Scores() {
    team1Score += 1;
}

void Soccer::team2Scores(){
    team2Score += 1;
}

void Soccer:: penaltyKicks(Team team1, Team team2) {
    //random time
    srand(time(0));
    //make counter for points
    int counter = 0;

    cout << "The game is a tie, it goes to penalty kicks. The " << team1.getTeamName() << " will shoot first." << endl << endl;
    //Team 1 has opportunity for penalty kicks
    for (int i = 0; i < 5; i++) {
        //make new random number to determine if team1 scores
        int randScore = rand() % 2;
        //if team1 scores, add score and change Team points
        if (randScore == 0) {
            team1Scores();
            team1.setPoints(team1Score);
            cout << team1.getTeamName() << " scored!" << endl;
            counter ++;
        }
            //if team1 did not score, print that they missed the shot
        else {
            cout << team1.getTeamName() << " missed the pk" << endl;
        }
    }

    cout << "The " << team1.getTeamName() << " got " << counter << "/5 penalty kicks" << endl << endl;
    cout << "The " << team2.getTeamName() << " will shoot next." << endl << endl;

    counter=0;
    //Team 2 has opportunity for penalty kicks
    for (int i = 0; i < 5; i++) {
        //make new random number to determine if team2 scores
        int randScore = rand() % 2;
        //if team2 scores, add score and change Team points
        if (randScore == 0) {
            team2Scores();
            team2.setPoints(team2Score);
            cout << team2.getTeamName() << " scored!" << endl;
            counter++;
        }
            //if team2 did not score, print that they missed the shot
        else {
            cout << team2.getTeamName() << " missed the pk" << endl;
        }
    }

    cout << "The " << team2.getTeamName() << " got " << counter << "/5 penalty kicks" << endl << endl;
}

string Soccer::determineWinner(Team team1, Team team2) {
    if (team1Score > team2Score){
        return team1.getTeamName();
    }
    else if (team1Score < team2Score){
        return team2.getTeamName();
    }
    else{
        penaltyKicks(team1, team2);
        determineWinner(team1, team2);
    }
}
