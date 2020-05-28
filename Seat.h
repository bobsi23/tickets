#pragma once
#include<string>
#include<cstdlib>
#include<ctime>
using std::string;

class Seat {
	bool booked;
	string note;
	int ticket_serial_number;
	
	// Credits: https://en.cppreference.com/w/cpp/numeric/random/srand
	int random_serial_number() {
		srand(time(nullptr));		// srand makes rand really generate random number
									// time(nullptr) is the number of seconds since 1970
		return rand() + 1;			// + 1 so that it's not 0
	}

public:
	Seat() {
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
			ticket_serial_number = random_serial_number();
		}
	}

	int get_ticket_serial_number() const {
		return ticket_serial_number;
	}
};
