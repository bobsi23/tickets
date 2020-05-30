#pragma once
#include <string>
#include <fstream>
using std::istream;
using std::ostream;
using std::string;
using std::to_string;

class Date {
	string date_as_string;		// YYYY-MM-DD

public:
	Date() {
		date_as_string = "";
	}

	Date(const string& _date) {
		date_as_string = _date;
	}

	Date(int year, int month, int day) {
		string month_as_string = to_string(month);
		string day_as_string = to_string(day);

		if (month < 10) {
			month_as_string= "0" + month_as_string;
		}
		if (day < 10) {
			day_as_string = "0" + day_as_string;
		}

		date_as_string = to_string(year) + "-" + month_as_string + "-" + day_as_string;
	}

	bool operator==(const Date& other) const {
		return date_as_string == other.date_as_string;
	}

	// "2000-05-12" < "2020-04-09"
	// "2019-09-08" < "2020-09-08"
	bool operator<(const Date& other) const {
		return date_as_string < other.date_as_string;
	}

	bool operator<=(const Date& other) const {
		return date_as_string <= other.date_as_string;
	}

	bool operator>=(const Date& other) const {
		return date_as_string >= other.date_as_string;
	}
	friend istream& operator>>(istream& in, Date& date);
	friend ostream& operator<<(ostream& out, const Date& date);
};

istream& operator>>(istream& in, Date& date) {
	in >> date.date_as_string;
	return in;
}

ostream& operator<<(ostream& out, const Date& date) {
	out << date.date_as_string;
	return out;
}

