void Window::start_game_loop(void(*fptr)(void)) {
	bool done = false;

	ALLEGRO_EVENT events;

	//start the timer
	al_start_timer(timer);
	al_start_timer(fps_timer);

	while (!done) {
		//set redraw to false by default
		bool redraw = false, fps = false;

		Window::temp_fps++;

		//done this way to process multiple events at once
		while (!al_is_event_queue_empty(event_queue)) {
			al_wait_for_event(event_queue, &events);
			//switch event type
			switch (events.type) {
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				done = true;
				break;
			case ALLEGRO_EVENT_TIMER:
				//if the timer goes off then set redraw to true and call given function
				if (events.timer.source == Window::timer) {
					redraw = true;
				} else {
					fps = true;
				}
				break;
			case ALLEGRO_EVENT_KEY_DOWN:
				//run all the key down events when a key is pressed
				for (unsigned int i = 0; i < Window::key_down_callbacks.size(); i++) {
					if (key_down_callbacks.at(i).first == events.keyboard.keycode) {
						key_down_callbacks.at(i).second();
					}
				}
				break;
			case ALLEGRO_EVENT_KEY_UP:
				//run all the key up events when a key is pressed
				for (unsigned int i = 0; i < Window::key_up_callbacks.size(); i++) {
					if (key_up_callbacks.at(i).first == events.keyboard.keycode) {
						key_up_callbacks.at(i).second();
					}
				}
				break;
			}
		}

		if (redraw) {
			//call given function
			fptr();
		}
		if (fps) {
			Window::fps = Window::temp_fps;
			Window::temp_fps = 0;
		}
	}
}