void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(3, "I was pressed!");
	} else {
		pros::lcd::clear_line(3);
	}
}