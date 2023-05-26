#pragma once 
#include <string>
#include "trip.h"
using namespace std;

class passenger
{
public:
    int TicketID;
    int TID;
    string name;

    passenger(int D, int TD, string nam);
};

class linkedQueue
{
private:
    struct Node
    {
        passenger Passenger;
        Node* next;

        Node(passenger p);
    };

    Node* frontptr;
    Node* rearptr;
    int Length;

public:

    linkedQueue();
    void enQueue(passenger p);
    void deQueue(int UID);
    void displayTicket(int tic);
    void displayUser();
    void displayAdmin(int Trinn);

    bool isEmpty();
};
