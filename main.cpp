//
// Created by India Davis on 2/22/22.
//
#include "Soccer.h"
#include "Team.h"
#include "Athlete.h"
#include "Sport.h"

using std::istream;

int main(){

    //make roster with athletes
    vector<Athlete> roster;
    roster.push_back(Athlete("Davis", 1, 0));
    roster.push_back(Athlete("Smith", 2, 0));
    roster.push_back(Athlete("White", 4, 0));
    roster.push_back(Athlete("Johnson", 6, 0));
    roster.push_back(Athlete("Donaldson", 8, 0));
    roster.push_back(Athlete("Reid", 9, 0));
    roster.push_back(Athlete("Allen", 12, 0));
    roster.push_back(Athlete("Blackwell", 16, 0));
    roster.push_back(Athlete("Carr", 18, 0));
    roster.push_back(Athlete("Jackson", 19, 0));
    roster.push_back(Athlete("Mann", 23, 0));
    //create team with roster
    Team team1= Team("Catamounts", 0, 0, roster);

    //make roster for team 2
    vector<Athlete> roster2;
    roster2.push_back(Athlete("Cantrell", 1, 0));
    roster2.push_back(Athlete("Simpson", 2, 0));
    roster2.push_back(Athlete("Garcia", 4, 0));
    roster2.push_back(Athlete("Jones", 6, 0));
    roster2.push_back(Athlete("Williams", 8, 0));
    roster2.push_back(Athlete("Brown", 9, 0));
    roster2.push_back(Athlete("Wilson", 12, 0));
    roster2.push_back(Athlete("Lee", 16, 0));
    roster2.push_back(Athlete("Wright", 18, 0));
    roster2.push_back(Athlete("King", 19, 0));
    roster2.push_back(Athlete("Roberts", 23, 0));
    //create team2 with new roster
    Team team2= Team("Eagles", 0, 0, roster2);

    //ask user which sport they would like to play
    cout << "Would you like to play soccer (s) or a different sport (o)?" << endl;

    //validate user input
    char sportChoice;
    char choice;
    cin >> sportChoice;
    while (sportChoice != 's' && sportChoice != 'o'){
        cout << "Please choice a valid option (s or o)" << endl;
        cin >> sportChoice;
    }

    //display which teams will be playing
    cout << "The two teams playing are " << team1.getTeamName() << " vs " << team2.getTeamName() << endl;

    //ask user if they would like to
    cout << "Would you like to view a team roster? (y or n)" << endl;
    cin >> choice;
    //validate input
    while (choice != 'y' && choice !='n'){
        cout << "Pick a valid option (y or n)" << endl;
        cin >> choice;
    }

    //if user wants to view roster
    if (choice == 'y'){
        //ask user which roster they would like to view
        cout << "Which team roster would you like to view? (Type 1 for " << team1.getTeamName() << ", 2 for " << team2.getTeamName() << ",or b for both)" << endl;
        cin >> choice;
        //validate choice
        if (choice != '1' && choice != '2' && choice != 'b'){
            cout << "Please enter valid choice (1,2,b)" << endl;
            cin >> choice;
        }

        //print roster depending on users choice
        if (choice == '1'){
            cout << team1.getTeamName() << " Roster:" << endl;
            team1.printRoster();
            }
        else if (choice == '2'){
            cout << team2.getTeamName() << " Roster:" << endl;
            team2.printRoster();
        }
        else {
            cout << team1.getTeamName() << " Roster:" << endl;
            team1.printRoster();
            cout << endl << team2.getTeamName() << " Roster:" << endl;
            team2.printRoster();
        }
    }

    //ask user to begin to play
    cout << endl << "choose p to play game" << endl;
    cin >> choice;
    //validate user choice
    if (choice != 'p'){
        cout << "choose p to play sports game" << endl;
        cin >> choice;
    }

    //create while loop to ask if user wants to play again at the end
    char playAgain= 'y';
    while (playAgain == 'y') {

        //Soccer game was chosen
        if (sportChoice == 's') {
            //create Soccer object and play game with given teams
            Soccer soccerGame = Soccer();
            soccerGame.playGame(team1, team2);
            //add to gamesWon depending on who won
            if (soccerGame.determineWinner(team1, team2) == team1.getTeamName()){
                team1.setGamesWon(team1.getGamesWon()+1);
            }
            else {
                team2.setGamesWon(team2.getGamesWon()+1);
            }
        }

            //Soccer game was not chosen
        else {
            //create Sports object and play game with given teams
            Sport sportsGame = Sport();
            sportsGame.playGame(team1, team2);
            //add to gamesWon depending on who won- do nothing if it is a tie
            if (sportsGame.determineWinner(team1, team2) == team1.getTeamName()){
                team1.setGamesWon(team1.getGamesWon()+1);
            }
            else if (sportsGame.determineWinner(team1, team2) == team2.getTeamName()){
                team2.setGamesWon(team2.getGamesWon()+1);
            }
        }

        cout << endl << team1.getTeamName() << " have won " << team1.getGamesWon() << " games" << endl;
        cout << team2.getTeamName() << " have won " << team2.getGamesWon() << " games" << endl;
        cout << endl << "Would you like to play again? (Press y for yes or any other letter to exit)" << endl;
        cin >> playAgain;
    }

    return 0;
}

