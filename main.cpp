#include <iostream>
#include <string>
#include "linkedlist.h"
#include "trip.h"
#include "passenger.h"
using namespace std;

int main() {
    int ch = 0, ch3 = 0, Length = 0, ticket = 0;
    LinkedList list;linkedQueue queue;
    trip t(990, 100, 40, "CAIRO", "ALEX", "7:00 AM"); list.addTrip(t);
    trip t1(991, 150, 50, "CAIRO", "ALEX", "10:00 AM");list.addTrip(t1);
    trip t2(992, 200, 50, "CAIRO", "ASWAN", "11:00 AM");list.addTrip(t2);
    trip t3(993, 120, 60, "FAYOM", "ALEX", "10:00 AM");list.addTrip(t3);
    trip t4(994, 300, 30, "ASWAN", "MATROH", "9:00 AM");list.addTrip(t4);
    cout << "************ RAILWAY RESERVATION SYSTEM ************\n\n";
    do {
        cout << "  MAIN MENU  \n";
        cout << "1 - Admin mode\n";
        cout << "2 - User mode \n";
        cout << "3 - Exit\n";
        cout << "Enter your choice : "; cin >> ch;
        system("cls");
        if (ch == 1) {
            string admin = "admin";
            string admin1;
            int pass = 12345;
            int password;
            cout << "Enter your Name and password \n";
            cout << "NAME : ";
            cin >> admin1;
            cout << "PASSWORD : ";
            cin >> password;

            if (pass == password && admin == admin1) {
                system("cls");
                cout << "******** ADMINISTRATOR MENU ******** \n\n";
                cout << "1 - view trip \n";
                cout << "2 - view ticket \n";
                cout << "3 - Add trip \n";
                cout << "4 - Remove trip \n";
                cout << "5 - Return to Main Menu \n";
                cout << "6 - Exit \n";
                cout << "Enter your choice : ";
                cin >> ch3;

                switch (ch3) {
                case 1: {
                    cout << "\n";
                    list.printTrips();
                    cout << "***** DATA CONCLUDED *****\n" << endl;
                    break;
                }
                case 2: {
                    cout << " Enter number of train : ";
                    int trainNumber;
                    cin >> trainNumber;
                    queue.displayAdmin(trainNumber);

                    cout << " Return to Main Menu (y/n) : ";
                    string y;
                    cin >> y;
                    cout << "\n";

                    if (y == "y" || y == "Y")
                        ch = 1;
                    else
                        ch = 0;
                    break;
                }
                case 3: {
                    int i2;
                    cout << "\n";
                    cout << " Enter number of ID : ";
                    cin >> i2;
                    cout << " Enter the price : ";
                    int pric;
                    cin >> pric;
                    cout << " Enter the capacity : ";
                    int capa;
                    cin >> capa;
                    cout << " Enter the Start station : ";
                    string station1;
                    cin >> station1;
                    cout << " Enter the End station : ";
                    string station2;
                    cin >> station2;
                    cout << " Enter the  time : ";
                    string tm;
                    cin.ignore();
                    getline(cin, tm);

                    trip t1(i2, pric, capa, station1, station2, tm);
                    list.addTrip(t1);

                    cout << " Return to Main Menu (y/n) : ";
                    string y;
                    cin >> y;
                    cout << "\n";

                    if (y == "y" || y == "Y")
                        ch = 1;
                    else
                        ch = 0;
                    break;
                }
                case 4: 
                {
                    int tripIDToRemove;
                    cout << "\n";
                    cout << " Enter ID trip : ";
                    cin >> tripIDToRemove;
                    list.removeTrip(tripIDToRemove);
                    cout << "\n";
                    break;
                }
                case 5: 
                {
                    ch = 1;
                    cout << "\n";
                    break;
                }
                default: 
                {
                    cout << "\n ***** THANK YOU ***** \n\n";
                    ch = 5;
                    break;
                }
                }    
            }
            else {
                cout << " \n **** Your password is wrong ****\n";
                ch == 1;
                cout << "********************************** \n "
                    << endl;
            }
        }
        if (ch == 2) {
            cout << "******** USER MENU ******** \n\n";
            cout << "1 - Book a ticket \n";
            cout << "2 - Cancel ticket \n";
            cout << "3 - Return to Main Menu \n";
            cout << "4 - Exit \n";
            cout << "Enter your choice : ";
            cin >> ch3;
            cout << endl;
            switch (ch3) {
            case 1: {
                cout << "Enter number of the train : ";
                int trainNumber;
                cin >> trainNumber;
                    Length = Length + 1;
                    cout << "Enter your name: ";
                    string name;
                    cin >> name;
                    passenger tt(Length, trainNumber, name);
                    queue.enQueue(tt);
                    cout << "Your ticket is:\n";
                    queue.displayTicket(Length);
                cout << "Return to Main Menu (y/n): ";
                string y;
                cin >> y;
                cout << "\n";

                if (y == "y" || y == "Y")
                    ch = 1;
                else
                    ch = 0;

                break;
            }
            case 2: {
                int usertick = 0;
                cout << " Enter your ticket : ";
                cin >> usertick;
                cout << endl;
                cout << "Your ticket cancel is  \n ";
                queue.displayTicket(usertick);

                cout << " Are you sure (y/n) ? : ";
                string sure;
                cin >> sure;

                if (sure == "y" || sure == "Y") {
                    queue.deQueue(usertick);
                    cout << "\n The ticket is cancelled . \n";
                }
                else {
                    cout << "The ticket is not cancelled . \n";
                }

                cout << "Return to Main Menu (y/n): ";
                string y;
                cin >> y;
                cout << "\n";

                if (y == "y" || y == "Y")
                    ch = 1;
                else
                    ch = 0;

                break;
            }
            case 3: {
                ch = 1;
                cout << "\n";
                break;
            }
            default:{
                cout << "\n ***** THANK YOU ***** \n\n";
                ch = 5;
                break;
            }
            }
        }
    } while (ch == 1 || ch == 2);
    return 0;
}
