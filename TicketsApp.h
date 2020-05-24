#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Hall.h"
#include "Event.h"
#include "Date.h"
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class TicketsApp {
	vector<Hall> halls;
    vector<Event> events;

    void add_event() {
        Date date;
        int index_of_hall;
        string event_name;

        cin >> date >> index_of_hall >> event_name;

        if (halls[index_of_hall].is_booked(date)) {
            cout << "Hall not available" << endl;
        }
        else {   
            Event new_event(event_name);
            events.push_back(new_event);
            halls[index_of_hall].book(date);
        }
    }

public:
    void run() {
        string command;

        while (true) {
            cin >> command;

            if (command == "addevent") {
                add_event();
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
