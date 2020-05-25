#pragma once
#include <string>

class Event {
	string event_name;
	int all_seats;
	int booked_seats;
	Date date;

public:
	Event() {
		event_name = "";
		all_seats = 0;
		booked_seats = 0;
		date = Date();
	}

	Event(const string& _event_name, int _all_seats, int _booked_seats, const Date& _date) {
		event_name = _event_name;
		all_seats = _all_seats;
		booked_seats = _booked_seats;
		date = _date;
	}

	string get_event_name() const {
		return event_name;
	}

	int get_all_seats() const {
		return all_seats;
	}

	int get_booked_seats() const {
		return booked_seats;
	}

	int get_free_seats() const {
		return all_seats - booked_seats;
	}

	Date get_date() const {
		return date;
	}
};
