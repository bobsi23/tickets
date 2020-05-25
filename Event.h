#pragma once
#include <string>
#include <vector>
#include "Seat.h"
using std::vector;
using std::string;

class Event {
	string event_name;
	Date date;
	vector<vector<Seat>> rows;

public:
	Event() {
		event_name = "";
		date = Date();
		rows = vector<vector<Seat>>();
	}

	Event(const string& _event_name, int number_of_rows, int number_of_colums, const Date& _date) {
		event_name = _event_name;
		date = _date;
		rows = vector<vector<Seat>>(number_of_rows, vector<Seat>(number_of_colums, Seat()));
	}

	string get_event_name() const {
		return event_name;
	}

	int get_all_seats() const {
		if (rows.empty()) {
			return 0;
		}
		else {
			int number_of_columns = rows[0].size();
			return rows.size() * number_of_columns;
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

	Date get_date() const {
		return date;
	}
};
