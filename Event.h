#pragma once
#include <string>
#include <vector>
#include "Seat.h"
#include "Row.h"
using std::vector;
using std::string;

class Event {
	string event_name; 
	Date date;
	vector<Row> rows;

public:
	Event() {
		event_name = "";
		date = Date();
	}

	Event(const string& _event_name, int number_of_rows, int number_of_colums, const Date& _date) {
		event_name = _event_name;
		date = _date;

		for (int i = 0; i < number_of_rows; ++i) {
			Row new_row(i, number_of_colums);
			rows.push_back(new_row);
		}
	}

	string get_event_name() const {
		return event_name;
	}

	int get_number_of_columns() const {
		if (rows.empty()) {
			return 0;
		}
		return rows[0].size();
	}

	int get_all_seats() const {
		if (rows.empty()) {
			return 0;
		}
		else {
			return rows.size() * get_number_of_columns();
		}
	}

	int get_booked_seats() const {
		int counter = 0;
		for (int i = 0; i < rows.size(); ++i) {
			for (int j = 0; j < rows[i].size(); ++j) {
				if (rows[i][j].is_booked()) {
					++counter;
				}
			}
		}
		return counter;
	}

	int get_free_seats() const {
		return get_all_seats() - get_booked_seats();
	}

	int get_booked_seats_which_are_not_bought() const {
		int counter = 0;
		for (int i = 0; i < rows.size(); ++i) {
			for (int j = 0; j < rows[i].size(); ++j) {
				if (rows[i][j].is_booked() && !rows[i][j].is_bought()) {
					++counter;
				}
			}
		}
		return counter;
	}

	Date get_date() const {
		return date;
	}

	bool is_valid(int row_number, int seat_number) const {
		return 0 <= row_number && row_number < rows.size()
			&& 0 <= seat_number && seat_number < get_number_of_columns();
	}

	bool is_booked(int row_number, int seat_number) const {
		return rows[row_number][seat_number].is_booked();
	}

	bool is_bought(int row_number, int seat_number) const {
		return rows[row_number][seat_number].is_bought();
	}

	void book_seat(int row_number, int seat_number, const string& note) {
		if (!is_booked(row_number, seat_number)) {
			rows[row_number][seat_number].book();
			rows[row_number][seat_number].set_note(note);
		}
	}

	void unbook_seat(int row_number, int seat_number) {
		if (is_booked(row_number, seat_number)) {
			rows[row_number][seat_number].unbook();
			rows[row_number][seat_number].set_note("");
		}
	}

	void buy_ticket(int row_number, int seat_number) {
		if (!is_bought(row_number, seat_number)) {
			rows[row_number][seat_number].buy();
		}
	}
};
