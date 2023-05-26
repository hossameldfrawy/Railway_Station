#pragma once
#include <string>
using namespace std;

class trip
{
public:
    int TrainID;
    int price;
    int capaity;
    string StartStation;
    string EndStation;
    string Time;

    trip(int ID, int pri, int cap, string start, string end, string t);

};
