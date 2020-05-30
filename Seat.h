#pragma once
#include<string>
#include<cstdlib>
#include<ctime>
#include"Date.h"
using std::string;

class Seat {
	int row_number;
	int seat_number;
	bool booked;
	string note;
	int ticket_serial_number;
	Date date_of_buying;

	// Credits: https://en.cppreference.com/w/cpp/numeric/random/srand
	int random_number() {
		srand(time(nullptr));		// srand makes rand really generate random number
									// time(nullptr) is the number of seconds since 1970
		return rand() % 10000;		// + 1 so that it's not 0
	}

	// Credits: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
	Date current_date() {
		time_t now = time(0);
		tm* local_time = localtime(&now);
		int year = 1900 + local_time->tm_year;
		int month = 1 + local_time->tm_mon;
		int day = local_time->tm_mday;
		Date date(year, month, day);
	}

public:
	Seat() {
		row_number = 0;
		seat_number = 0;
		booked = false;
		note = "";
		ticket_serial_number = 0;
	}

	Seat(int _row_number, int _seat_number) {
		row_number = _row_number;
		seat_number = _seat_number;
		booked = false;
		note = "";
		ticket_serial_number = 0;
	}

	bool is_booked() const {
		return booked;
	}

	void book() {
		booked = true;
	}

	void unbook() {
		booked = false;
	}


	void set_note(const string& _note) {
		note = _note;
	}

	string get_note() const {
		return note;
	}


	bool is_bought() const {
		return ticket_serial_number != 0;
	}

	void buy() {
		if (!is_bought()) {
			book();
			ticket_serial_number = (row_number * 100 + seat_number) * 10000 + random_number();
			date_of_buying = current_date();
		}
	}

	int get_ticket_serial_number() const {
		return ticket_serial_number;
	}
};
