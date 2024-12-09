void ScrollView::MessageReceiver() {
  int counter_event_id = 0; // ongoing counter
  char *message = nullptr;
  // Wait until a new message appears in the input stream_.
  do {
    message = ScrollView::GetStream()->Receive();
  } while (message == nullptr);

  // This is the main loop which iterates until the server is dead (strlen =
  // -1). It basically parses for 3 different messagetypes and then distributes
  // the events accordingly.
  while (true) {
    // The new event we create.
    std::unique_ptr<SVEvent> cur(new SVEvent);
    // The ID of the corresponding window.
    int window_id;

    int ev_type;

    int n;
    // Fill the new SVEvent properly.
    sscanf(message, "%d,%d,%d,%d,%d,%d,%d,%n", &window_id, &ev_type, &cur->x, &cur->y, &cur->x_size,
           &cur->y_size, &cur->command_id, &n);
    char *p = (message + n);

    svmap_mu->lock();
    cur->window = svmap[window_id];

    if (cur->window != nullptr) {
      auto length = strlen(p);
      cur->parameter = new char[length + 1];
      strcpy(cur->parameter, p);
      if (length > 0) { // remove the last \n
        cur->parameter[length - 1] = '\0';
      }
      cur->type = static_cast<SVEventType>(ev_type);
      // Correct selection coordinates so x,y is the min pt and size is +ve.
      if (cur->x_size > 0) {
        cur->x -= cur->x_size;
      } else {
        cur->x_size = -cur->x_size;
      }
      if (cur->y_size > 0) {
        cur->y -= cur->y_size;
      } else {
        cur->y_size = -cur->y_size;
      }
      // Returned y will be the bottom-left if y is reversed.
      if (cur->window->y_axis_is_reversed_) {
        cur->y = cur->window->TranslateYCoordinate(cur->y + cur->y_size);
      }
      cur->counter = counter_event_id;
      // Increase by 2 since we will also create an SVET_ANY event from cur,
      // which will have a counter_id of cur + 1 (and thus gets processed
      // after cur).
      counter_event_id += 2;

      // In case of an SVET_EXIT event, quit the whole application.
      if (ev_type == SVET_EXIT) {
        SendRawMessage("svmain:exit()");
        break;
      }

      // Place two copies of it in the table for the window.
      cur->window->SetEvent(cur.get());

      // Check if any of the threads currently waiting want it.
      std::pair<ScrollView *, SVEventType> awaiting_list(cur->window, cur->type);
      std::pair<ScrollView *, SVEventType> awaiting_list_any(cur->window, SVET_ANY);
      std::pair<ScrollView *, SVEventType> awaiting_list_any_window((ScrollView *)nullptr,
                                                                    SVET_ANY);
      waiting_for_events_mu->lock();
      if (waiting_for_events.count(awaiting_list) > 0) {
        waiting_for_events[awaiting_list].second = cur.get();
        waiting_for_events[awaiting_list].first->Signal();
      } else if (waiting_for_events.count(awaiting_list_any) > 0) {
        waiting_for_events[awaiting_list_any].second = cur.get();
        waiting_for_events[awaiting_list_any].first->Signal();
      } else if (waiting_for_events.count(awaiting_list_any_window) > 0) {
        waiting_for_events[awaiting_list_any_window].second = cur.get();
        waiting_for_events[awaiting_list_any_window].first->Signal();
      }
      waiting_for_events_mu->unlock();
      // Signal the corresponding semaphore twice (for both copies).
      ScrollView *sv = svmap[window_id];
      if (sv != nullptr) {
        sv->Signal();
        sv->Signal();
      }
    }
    svmap_mu->unlock();

    // Wait until a new message appears in the input stream_.
    do {
      message = ScrollView::GetStream()->Receive();
    } while (message == nullptr);
  }
}