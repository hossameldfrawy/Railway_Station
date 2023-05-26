#pragma once
#include "trip.h"

class Node {
public:
    trip Trip;
    Node* next;

    Node(trip t);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void addTrip(trip t);
    void removeTrip(int tripID);
    void printTrips();
};
