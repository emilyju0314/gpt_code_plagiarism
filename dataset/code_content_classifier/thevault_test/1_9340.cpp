float bangbang::update(float input, float setpoint, float target) {
	float error = setpoint - input;
	if (error > 0 && error > this->threshold) {
		return this->max;
	} else if (error > 0 && error <= this->threshold) {
		return this->min;
	} else if (error < 0 && fabs(error) > fabs(this->threshold)) {
		return -this->max;
	} else if (error < 0 && fabs(error) <= fabs(this->threshold)) {
		return -this->min;
	} else {
		return 0;
	}
}