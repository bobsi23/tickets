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

    //Добавя ново представление на дата <date> с име <name> в зала <hall>.
    //Ако в тази зала вече има друго представление на същата дата, командата да върне грешка.
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
    
   // Извежда справка за свободните места за представление с име <name> на дата <date>(непродадени и незапазени билети).

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
    
   // Запазва билет за представление с име <name> на <date> на ред <row> и място <seat>, като добавя бележка <note>.

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

   // Отменя резервация за представление с име <name> на <date> на ред <row> и място <seat>.

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
        else {
            cout << "Event not found" << endl;
        }
    }

    // TODO: Make this better
    bool isDate(const string& s) {
        return s[0] >= '0' && s[0] <= '9';
    }

    void bookings() {
        if (cin.peek() == '\n') {
            for (int i = 0; i < events.size(); ++i) {
                cout << events[i].get_event_name() << ", " << events[i].get_date() << ": "
                    << events[i].get_booked_seats_which_are_not_bought() << endl;
            }
        }
        else {
            string temporary;
            cin >> temporary;

            if (cin.peek() == '\n') {
                if (isDate(temporary)) {
                    for (int i = 0; i < events.size(); ++i) {
                        if (events[i].get_date() == temporary) {
                            cout << events[i].get_event_name() << ": "
                                << events[i].get_booked_seats_which_are_not_bought() << endl;
                        }
                    }
                }
                else {
                    for (int i = 0; i < events.size(); ++i) {
                        if (events[i].get_event_name() == temporary) {
                            cout << events[i].get_date() << ": "
                                << events[i].get_booked_seats_which_are_not_bought() << endl;
                        }
                    }
                }
            }
            else {
                Date date(temporary);
                string event_name;
                cin >> event_name;

                Event* found_event = find_event(event_name, date);

                if (found_event != nullptr) {
                    cout << found_event->get_booked_seats_which_are_not_bought() << endl;
                }
                else {
                    cout << "Event not found" << endl;
                }
            }
        }
    }

   // Прави проверка за валидност на билет, като по дадения код <code> се извлича номера на мястото или се връща грешка, ако кодът е невалиден).

    void check() {
        

    }
   // Извежда справка за закупени билети от дата <from> до дата <to> в
    void report() {
        Date date_from;
        Date date_to;
        cin >> date_from >> date_to;
        
        int hall_index;
        bool we_have_read_hall = false;

        if (cin.peek()!='\n') {
            cin >> hall_index;
            we_have_read_hall = true;
        }
        
        for (int i = 0; i < events.size(); ++i) {
            if (!we_have_read_hall || events[i].get_hall_index() == hall_index) {
                cout << events[i].get_event_name() << ", " << events[i].get_date() << ": "
                    << events[i].get_bought_seats_in_date_interval(date_from, date_to) << endl;
            }
        }
    }

public:
    void run() {
        cout << "Please enter all dates in the format: YYYY-MM-DD" << endl;

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
