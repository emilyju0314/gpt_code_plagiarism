void
TrafficSource::draw(View * view, double time) {
	double label_width, label_height, label_x, label_y;
	int paint_color_id; 
	static char full_label[128];

	// Draw label centered inside of border
	if (label_) {
		//sprintf(full_label, "%s - %d", label_, number_);
		sprintf(full_label, "%s", label_);
		
		// We have to keep calculting the label width and height because
		// we have no way of knowing if the user has zoomed in or out 
		// on the current network view.
		label_height = 0.9 * height_;
		label_width = view->getStringWidth(full_label, label_height);

		// Add 10% of padding to width for the box
		setWidth(1.1 * label_width);
		
		// Center label in box
		label_x = x_ + (width_ - label_width);
		label_y = y_ + (height_ - label_height);

		view->string(full_label, label_x , label_y, label_height, NULL);
		
		update_bb();
	}

	
	// Draw Rectangle Border

	if (timelist.isOn(time)) {
		paint_color_id = Paint::instance()->lookup("darkgreen", 3);
		if (paint_color_id >= 0) {
			view->rect(x_, y_, x_ + width_, y_ + height_, paint_color_id);
		}
	} else {
	view->rect(x_, y_, x_ + width_, y_ + height_ , paint_);
	}
}