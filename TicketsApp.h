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

    Event* find_event(const string& event_name, const Date& date) {
        for (int i = 0; i < events.size(); ++i) {
            if (events[i].get_event_name() == event_name && events[i].get_date() == date) {
                return &(events[i]);
            }
        }
        return nullptr;
    }

    void add_event() {
        Date date;
        int index_of_hall;
        string event_name;

        cin >> date >> index_of_hall >> event_name;

        if (halls[index_of_hall].is_booked(date)) {
            cout << "Hall not available" << endl;
        }
        else {
            int number_of_rows = halls[index_of_hall].get_number_of_rows();
            int number_of_colums = halls[index_of_hall].get_number_of_colums();
            Event new_event(event_name, number_of_rows, number_of_colums, date);
            events.push_back(new_event);
            halls[index_of_hall].book(date);
        }
    }

    void free_seats() {
        string event_name;
        Date date;

        cin >> event_name >> date;

        Event* found_event = find_event(event_name, date);

        if (found_event != nullptr){
            cout << found_event->get_free_seats() << endl;
        }
        else {
            cout << "Event not found" << endl;
        }
    }

    void book() {
        int row_number;
        int seat_number;
        Date date;
        string event_name;
        string note;

        cin >> row_number >> seat_number >> date >> event_name >> note;

        Event* found_event = find_event(event_name, date);

        if (found_event != nullptr) {
            if (found_event->is_valid(row_number, seat_number) && !found_event->is_booked(row_number, seat_number)) {
                found_event->book_seat(row_number, seat_number, note);
            }
            else {
                cout << "Seat not available or already booked" << endl;
            }
        }
        else {
            cout << "Event not found" << endl;
        }
    }

    void unbook() {
        int row_number;
        int seat_number;
        Date date;
        string event_name;

        cin >> row_number >> seat_number >> date >> event_name;

        Event* found_event = find_event(event_name, date);

        if (found_event != nullptr) {
            if (found_event->is_valid(row_number, seat_number) && found_event->is_booked(row_number, seat_number)) {
                found_event->unbook_seat(row_number, seat_number);
            }
            else {
                cout << "Seat not available or not booked" << endl;
            }
        }
        else {
            cout << "Event not found" << endl;
        }
    }

    // Ако има такова събитие на съответната дата и валидно и некупено място,
    // купуваме билет = правим мястото зеато и купено(с уникален номер, който съдържа инфо мястото)
    void buy() {
        int row_number;
        int seat_number;
        Date date;
        string event_name;

        cin >> row_number >> seat_number >> date >> event_name;

        Event* found_event = find_event(event_name, date);

        if (found_event != nullptr) {
            if (found_event->is_valid(row_number, seat_number) && !found_event->is_bought(row_number, seat_number)) {
                found_event->buy_ticket(row_number, seat_number);
            }
            else {
                cout<< "Seat not available or already bought, choose another seat" << endl;
            }
        }
    }

    void bookings() {

    }

    void check() {

    }

    void report() {

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
                free_seats();
            }
            else if (command == "book") {
                book();
            }
            else if (command == "unbook") {
                unbook();
            }
            else if (command == "buy") {
                buy();
            }
            else if (command == "bookings") {
                bookings();
            }
            else if (command == "check") {
                check();
            }
            else if (command == "report") {
                report();
            }
        }
    }
};
