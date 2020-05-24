#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Hall.h"
using std::string;
using std::vector;
using std::cin;

class TicketsApp {
	vector<Hall> halls;

public:

    void run() {
        string command;

        while (true) {
            cin >> command;

            if (command == "addevent") {

            }
            else if (command == "freeseats") {

            }
            else if (command == "book") {

            }
            else if (command == "unbook") {

            }
            else if (command == "buy") {

            }
            else if (command == "bookings") {

            }
            else if (command == "check") {

            }
            else if (command == "report") {

            }
        }
    }
};
