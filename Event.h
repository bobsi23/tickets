#pragma once
#include <string>

class Event {
	string event_name;

public:
	Event() {
		event_name = "";
	}

	Event(const string& _event_name) {
		event_name = _event_name;
	}

	string get_event_name() const {
		return event_name;
	}
};
