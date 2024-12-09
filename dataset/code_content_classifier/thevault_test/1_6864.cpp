bool
TimeList::isOn(double time) {
	TimeElement * element;
	bool on = false;

	for (element = head(); element; element = element->next_) {
		if (time < element->time_) {
				break;
		}

		if (on) {
			on = false;
		} else {
			on = true;
		}
	}
	return on;
}