#pragma once
#include<vector>
#include "Seat.h"
using std::vector;

class Row {
	int row_number;
	vector<Seat> seats;

public:
	Row() {
		row_number = 0;
	}

	Row(int _row_number, int number_of_seats) {
		row_number = _row_number;
		for (int i = 0; i < number_of_seats; ++i) {
			Seat seat(_row_number, i);
			seats.push_back(seat);
		}
	}

	int size() const {
		return seats.size();
	}

	Seat& operator[](int i) {
		return seats[i];
	}

	const Seat& operator[](int i) const {
		return seats[i];
	}
};