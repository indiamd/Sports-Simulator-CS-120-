//
// Created by India Davis on 2/22/22.
//

#include "Athlete.h"

Athlete:: Athlete() {
    lastName = "Davis";
    jerseyNum = 1;
    pointsScored = 0;
}

Athlete:: Athlete(string name, int num, int pts) {
    lastName = name;
    jerseyNum = num;
    pointsScored = pts;
}


    string Athlete:: getLastName() const{
        return lastName;
    }

    int Athlete:: getJerseyNum() const{
        return jerseyNum;
    }

    int Athlete:: getPointsScored() const{
        return pointsScored;
    }

    //setters
    void Athlete:: setLastName(int name){
        lastName = name;
    }

    void Athlete:: setJerseyNum(int num){
        jerseyNum = num;
    }

    void Athlete:: setPointsScored(int pts){
        pointsScored = pts;
    }

    void Athlete:: addPointScored(int num){
        pointsScored+= num;
    }