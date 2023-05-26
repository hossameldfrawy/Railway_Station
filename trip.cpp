#include "linkedlist.h"
#include "trip.h"
#include "passenger.h"
using namespace std;

trip::trip(int ID, int pri, int cap, string start, string end, string t) {
    TrainID = ID;
    price = pri;
    capaity = cap;
    StartStation = start;
    EndStation = end;
    Time = t;
}

