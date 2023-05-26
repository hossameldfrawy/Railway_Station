#include "linkedlist.h"
#include <iostream>

Node::Node(trip t) : Trip(t), next(nullptr) {}
LinkedList::LinkedList() {
    head = nullptr;
}
void LinkedList::addTrip(trip t) {
    Node* newNode = new Node(t);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void LinkedList::removeTrip(int tripID) {
    if (head == nullptr) {
        return;
    }

    if (head->Trip.TrainID == tripID) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr && current->Trip.TrainID != tripID) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return;
    }

    previous->next = current->next;
    delete current;
}
void LinkedList::printTrips() {
    Node* current = head;
    while (current != nullptr)
    {
        cout << "\n";
        cout << "- Num of Train: " << current->Trip.TrainID << endl;
        cout << "- price: " << current->Trip.price << endl;
        cout << "- Capacity: " << current->Trip.capaity << endl;
        cout << "- Start station: " << current->Trip.StartStation << endl;
        cout << "- End station: " << current->Trip.EndStation << endl;
        cout << "- Time: " << current->Trip.Time << endl;
        cout << endl;

        current = current->next;
    }
}
