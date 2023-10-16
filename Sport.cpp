//
// Created by India Davis on 2/22/22.
//

#include "Sport.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::istream;
using namespace std;

Sport::Sport(){
    playersOnField= 6;
    gameLength= 30;
    team1Score= 0;
    team2Score= 0;
}

Sport::Sport(int length, int t1, int t2){
    playersOnField= 6;
    gameLength= length;
    team1Score= t1;
    team2Score= t2;
}

int Sport::getPlayers() const {
    return playersOnField;
}

int Sport::getGameLength() const {
    return gameLength;
}

int Sport::getTeam1Score() const {
    return team1Score;
}

int Sport::getTeam2Score() const {
    return team2Score;
}

void Sport::setPlayers(int players) {
    playersOnField = players;
}

void Sport::setGameLength(int length){
    gameLength = length;
}

void Sport::setTeam1Score(int t1) {
    team1Score = t1;
}

void Sport::setTeam2Score(int t2) {
    team2Score = t2;
}

void Sport::team1Scores() {
    team1Score+=3;
}

void Sport::team2Scores(){
    team2Score+=3;
}

string Sport::determineWinner(Team team1, Team team2) {
    if (team1Score > team2Score){
        return team1.getTeamName();
    }
    else if (team1Score < team2Score){
        return team2.getTeamName();
    }
    else{
        return "Tie";
    }
}

void Sport:: playGame(Team team1, Team team2){
    //reset number of points from each team to 0
    team1.setPoints(0);
    team2.setPoints(0);
    //initialize random number for number of points scored in the game
    srand(time(0));
    int randNum = (rand()%MAX_POINTS);

    //for loop changes size depending on random # of determined points scored in the game
    for (int i=0; i<randNum; i++){
        //make new random number to determine which team scores
        int randTeam = rand()%2;
        //if team1 scores, add score and change Team points
        if (randTeam == 0){
            team1Scores();
            team1.setPoints(team1Score);
            cout << team1.getTeamName() << " scored!" << endl;
        }
        //if team2 scores, add score and change Team points
        else{
            team2Scores();
            team2.setPoints(team2Score);
            cout << team2.getTeamName() << " scored!" << endl;
        }
    }

    //print final scores
    cout << "The final score is " << team1.getPoints() << ":" << team2.getPoints() << endl << endl;
    //determine and print winner
    string winner= determineWinner(team1, team2);
    if (winner == team1.getTeamName()) {
        cout << "The winner is " << winner << endl;
        team1.setGamesWon(team1.getGamesWon() + 1);
    }
    else if(winner == team2.getTeamName()) {
        cout << "The winner is " << winner << endl;
        team2.setGamesWon(team2.getGamesWon() + 1);
    }
    else {
        cout << "It's a tie" << endl;
    }

}

