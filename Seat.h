#pragma once
#include<string>
using std::string;

class Seat {
	bool booked;
	string note;
	
public:
	Seat() {
		booked = false;
		note = "";
	}

	bool is_booked() const {
		return booked;
	}
	
	bool book() {
		booked = true;
	}

	bool unbook() {
		booked = false;
	}

	void set_note(const string& _note) {
		note = _note;
	}

	string get_note() const {
		return note;
	}
};
