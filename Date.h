#pragma once
#include <string>
#include <fstream>
using std::istream;
using std::string;

class Date {
	string date_as_string;

public:
	bool operator==(const Date& other) const {
		return date_as_string == other.date_as_string;
	}

	friend istream& operator>>(istream& in, Date& date);
};

istream& operator>>(istream& in, Date& date) {
	in >> date.date_as_string;
	return in;
}
