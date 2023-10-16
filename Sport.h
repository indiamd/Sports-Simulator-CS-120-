//
// Created by India Davis on 2/22/22.
//

#ifndef M2OEP_LARGE_IDAVIS1_SPORT_H
#define M2OEP_LARGE_IDAVIS1_SPORT_H

#include "Team.h"
#include "Athlete.h"
#include <string>

class Sport{
protected:
    int playersOnField;
    int gameLength;
    int team1Score;
    int team2Score;

private:
    const int MAX_POINTS= 75;

public:

    //Constructors
    Sport();
    Sport(int length, int t1, int t2);

    //getters
    int getPlayers() const;
    int getGameLength() const;
    int getTeam1Score() const;
    int getTeam2Score() const;

    //setters
    void setPlayers(int players);
    void setGameLength(int length);
    void setTeam1Score(int t1);
    void setTeam2Score(int t2);


    //team scores
    //takes in nothing
    //returns nothing
    //adds 3 to team score
    virtual void team1Scores();
    virtual void team2Scores();

    //determines winner by comparing num of points
    //modifies nothing
    //return string of which team won
    virtual string determineWinner(Team team1, Team team2);

    //randomizes a game of Sport
    //modifies team1Score and team2Score
    //does not return anything
    void playGame(Team team1, Team team2);

};



#endif //M2OEP_LARGE_IDAVIS1_SPORT_H
