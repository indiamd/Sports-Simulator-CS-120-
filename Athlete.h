//
// Created by India Davis on 2/22/22.
//

#ifndef M2OEP_LARGE_IDAVIS1_ATHLETE_H
#define M2OEP_LARGE_IDAVIS1_ATHLETE_H

#include <string>
using namespace std;
using std::string;

class Athlete{
private:
    string lastName;
    int jerseyNum;
    int pointsScored;

public:

    //constructors
    Athlete();
    Athlete(string name, int num, int pts);

    //getters
    string getLastName() const;
    int getJerseyNum() const;
    int getPointsScored() const;

    //setters
    void setLastName(int name);
    void setJerseyNum(int num);
    void setPointsScored(int pts);

    void addPointScored(int num);

};


#endif //M2OEP_LARGE_IDAVIS1_ATHLETE_H
