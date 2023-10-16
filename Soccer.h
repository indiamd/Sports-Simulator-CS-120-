//
// Created by India Davis on 2/22/22.
//

#ifndef M2OEP_LARGE_IDAVIS1_SOCCER_H
#define M2OEP_LARGE_IDAVIS1_SOCCER_H

#include "Sport.h"

class Soccer : public Sport {
private:
    int yellowCards;
    int redCards;
    bool pks;
    const int MAX_POINTS= 20;

public:
    //constructors
    Soccer();
    Soccer(int length, int t1, int t2, int yellow, int red, bool pks);

    //getters
    int getYellowCards();
    int getRedCards();
    bool getPks();

    //setters
    void setYellowCards(int yellow);
    void setRedCards(int red);
    void setPks(bool pk);

    //teams score methods- change number of points to add when scores
    //override
    virtual void team1Scores() override;
    virtual void team2Scores() override;

    //pks
    //to be used in determining winner
    //lets each team shoot 5 times
    void penaltyKicks(Team team1, Team team2);

    //determine winner
    //compare num of points to see which team won
    //cannot be a tie- call pks to make sure a team wins
    //override
    virtual string determineWinner(Team team1, Team team2) override;



};


#endif //M2OEP_LARGE_IDAVIS1_SOCCER_H
