//
// Created by India Davis on 2/27/22.
//
#include "Sport.h"
#include "Soccer.h"
#include "Team.h"
#include "Athlete.h"

bool testAthlete();
bool testTeam();
bool testSport();
bool testSoccer();

int main() {
    if (testAthlete()) {
        cout << "Passed all Athlete test cases" << endl;
    }

    if (testTeam()) {
        cout << "Passed all Team test cases" << endl;
    }

    if (testSport()) {
        cout << "Passed all Sport test cases" << endl;
    }

    if (testSoccer()) {
        cout << "Passed all Soccer test cases" << endl;
    }

    return 0;
}


bool testAthlete(){
    bool passed = true;

    Athlete a = Athlete();
    if (a.getLastName()!= "Davis"){
        cout << "FAILED default constructor test case" << endl;
        passed = false;
    }
    if (a.getJerseyNum()!= 1){
        cout << "FAILED default constructor test case" << endl;
        passed = false;
    }
    if (a.getPointsScored()!=0){
        cout << "FAILED default constructor test case" << endl;
        passed = false;
    }

    a = Athlete("Wilson", 7, 2);
    if (a.getLastName()!= "Wilson"){
        cout << "FAILED Wilson,7,2 test case" << endl;
        passed = false;
    }
    if (a.getJerseyNum()!= 7){
        cout << "FAILED Wilson,7,2 test case" << endl;
        passed = false;
    }
    if (a.getPointsScored()!=2){
        cout << "FAILED Wilson,7,2 test case" << endl;
        passed = false;
    }
    a.addPointScored(3);
    if (a.getPointsScored()!=5){
        cout << "FAILED add points test case" << endl;
        passed = false;
    }

    return passed;
}





bool testTeam(){
    bool passed = true;

    vector<Athlete> roster = {};
    Team t = Team("Test", 12, 2, roster);
    Athlete a = Athlete();
    t.addToRoster(a);

    if (t.getTeamName()!="Test"){
        cout << "FAILED Test,12,2,roster test case 1" << endl;
        passed = false;
    }

    if (roster.size()!=0){
        cout << "FAILED Test,12,2,roster test case 2" << endl;
        passed = false;
    }

    if ( t.getPoints()!=12){
        cout << "FAILED Test,12,2,roster test case 3" << endl;
        passed = false;
    }

    if (t.getGamesWon()!=2){
        cout << "FAILED Test,12,2,roster test case 4" << endl;
        passed = false;
    }



    cout << "Testing printRoster method:" << endl;
    t.printRoster();
    cout << "end printRoster test" << endl;

    t.clearRoster();
    if (roster.size() != 0){
        cout << "FAILED clear roster test case" << endl;
        passed = false;
    }



    return passed;
}


bool testSport(){
    bool passed = true;

    //create teams for initializing sport
    Team t1 = Team();
    Team t2 = Team();
    Sport s = Sport();

    //add scores to each team
    s.team1Scores();
    s.team1Scores();
    s.team1Scores();
    s.team2Scores();

    //test team1Scores/team2Scores method
    if (s.getTeam1Score() != 9){
        cout << "FAILED team1Scores methods test case" << endl;
        passed = false;
    }
    if (s.getTeam2Score() != 3){
        cout << "FAILED team2Scores methods test case" << endl;
        passed = false;
    }

    //test Determine Winner method
    s.setTeam1Score(9);
    s.setTeam2Score(9);
    if (s.determineWinner(t1, t2)!="Tie"){
        cout << "FAILED 9,9 determine winner test case" << endl;
        passed = false;
    }
    s.setTeam1Score(12);
    s.setTeam2Score(8);
    if (s.determineWinner(t1, t2) != t1.getTeamName()){
        cout << "FAILED 12,8 determine winner test case" << endl;
        passed = false;
    }

    s.setTeam1Score(8);
    s.setTeam2Score(12);
    if (s.determineWinner(t1, t2)!= t1.getTeamName()){
        cout << "FAILED 8,12 determine winner test case" << endl;
        passed = false;
    }

    cout << "Testing play game method: " << endl;
    s.playGame(t1, t2);
    cout << endl << "End play game method test" << endl;

    return passed;
}

bool testSoccer(){
    bool passed = true;
    Team t1 = Team();
    Team t2 = Team();
    Soccer s = Soccer();

    //add scores to each team
    s.team1Scores();
    s.team1Scores();
    s.team1Scores();
    s.team2Scores();

    //test team1Scores/team2Scores method
    if (s.getTeam1Score() != 3){
        cout << "FAILED team1Scores methods test case" << endl;
        passed = false;
    }
    if (s.getTeam2Score() != 1){
        cout << "FAILED team2Scores methods test case" << endl;
        passed = false;
    }

    //test Determine Winner method
    s.setTeam1Score(9);
    s.setTeam2Score(9);
    if (s.determineWinner(t1, t2)=="Tie"){
        cout << "FAILED 9,9 Soccer determine winner test case: cannot be a tie" << endl;
        passed = false;
    }
    s.setTeam1Score(12);
    s.setTeam2Score(8);
    if (s.determineWinner(t1, t2) != t1.getTeamName()){
        cout << "FAILED 12,8 determine winner test case" << endl;
        passed = false;
    }

    s.setTeam1Score(8);
    s.setTeam2Score(12);
    if (s.determineWinner(t1, t2)!= t1.getTeamName()){
        cout << "FAILED 8,12 determine winner test case" << endl;
        passed = false;
    }

    cout << "Testing play game method: " << endl;
    s.playGame(t1, t2);
    cout << endl << "End play game method test" << endl;

    return passed;
}