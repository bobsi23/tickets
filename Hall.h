#pragma once
#include <vector>
#include "Date.h"

using std::vector;

class Hall {
	int number;
	int rows;
	int seats_per_row;
	vector<Date> booked_dates;

public:
	
	Hall() {
		number = 0;
		rows = 0;
		seats_per_row = 0;
		booked_dates = vector<Date>();
	}

	Hall(int  _number, int _rows, int _seats_per_row) {
		number = _number;
		rows = _rows;
		seats_per_row = _seats_per_row;
		booked_dates = vector<Date>();
	}

	void book(const Date& date) {
		booked_dates.push_back(date);
	}

	bool is_free(const Date& date) const {
		for (int i = 0; i < booked_dates.size(); ++i) {
			if (booked_dates[i] == date) {
				return false;
			}
		}
		return true;
	}
	
	bool is_booked(const Date& date) const {
		return !is_free(date);
	}

	
};