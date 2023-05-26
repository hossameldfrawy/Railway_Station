#pragma once 
#include"trip.h"
#include "passenger.h"
#include<iostream>
#include <string>
using namespace std;

linkedQueue::Node::Node(passenger p) : Passenger(p), next(nullptr) {}
linkedQueue::linkedQueue() : frontptr(NULL), rearptr(NULL), Length(0) {}


passenger::passenger(int D, int TD, string nam)
{
    TicketID = D;
    TID = TD;
    name = nam;

}
void linkedQueue::displayTicket(int tic)
{
    Node* current = frontptr;

    while (current != nullptr)
    {
        if (current->Passenger.TicketID == tic)
        {
            cout << "*********************************";
            cout << "\n" << " your name : " << current->Passenger.name;
            cout << "\n" << " your Ticket ID : " << current->Passenger.TicketID;
            cout << "\n" << " your TID : " << current->Passenger.TID << endl;
            cout << "*********************************\n";
        }
        current = current->next;
    }
}
void linkedQueue::displayUser()
{

    Node* current = frontptr;

    while (current != nullptr)
    {
        cout << "*********************************";
        cout << "\n" << " your name : " << current->Passenger.name;
        cout << "\n" << " your Ticket ID : " << current->Passenger.TicketID;
        cout << "\n" << " your TID : " << current->Passenger.TID << endl;
        cout << "*********************************\n";

        current = current->next;
    }
}
void linkedQueue::displayAdmin(int Trinn)
{
    Node* current = frontptr;

    while (current != nullptr)
    {
        if (current->Passenger.TID == Trinn)
        {
            cout << "*********************************";
            cout << "\n" << " your name : " << current->Passenger.name;
            cout << "\n" << " your Ticket ID : " << current->Passenger.TicketID;
            cout << "\n" << " your TID : " << current->Passenger.TID << endl;
            cout << "*********************************\n";
        }
        current = current->next;
    }

}
bool linkedQueue::isEmpty()
{
    return Length == 0;
}
void linkedQueue::enQueue(passenger p)
{
    Node* current = frontptr;


    Node* newptr = new Node(p);

   if (isEmpty())
   {
                    frontptr = newptr;
                    rearptr = newptr;
   }
   else

  {
                    rearptr->next = newptr;
                    rearptr = newptr;
      }

           Length++;
}
void linkedQueue::deQueue(int UID)
{
    if (isEmpty())
    {
        cout << "Empty Queue, can't Dequeue\n";
        return;
    }

    Node* tempPtr = frontptr;
    Node* prevPtr = nullptr;

    if (frontptr->Passenger.TicketID == UID)
    {
        frontptr = frontptr->next;

        if (frontptr == nullptr)
            rearptr = nullptr;

        delete tempPtr;
        Length--;
        return;
    }

    while (tempPtr != nullptr && tempPtr->Passenger.TicketID != UID)
    {
        prevPtr = tempPtr;
        tempPtr = tempPtr->next;
    }

    if (tempPtr == nullptr)
    {
        cout << "User not found in the queue\n";
        return;
    }

    prevPtr->next = tempPtr->next;

    if (tempPtr == rearptr)
        rearptr = prevPtr;

    delete tempPtr;
    Length--;
}
