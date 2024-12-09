void ScrollView::Initialize(const char *name, int x_pos, int y_pos, int x_size, int y_size,
                            int x_canvas_size, int y_canvas_size, bool y_axis_reversed,
                            const char *server_name) {
  // If this is the first ScrollView Window which gets created, there is no
  // network connection yet and we have to set it up in a different thread.
  if (stream_ == nullptr) {
    nr_created_windows_ = 0;
    stream_ = new SVNetwork(server_name, kSvPort);
    waiting_for_events_mu = new std::mutex();
    svmap_mu = new std::mutex();
    SendRawMessage("svmain = luajava.bindClass('com.google.scrollview.ScrollView')\n");
    std::thread t(&ScrollView::MessageReceiver);
    t.detach();
  }

  // Set up the variables on the clientside.
  nr_created_windows_++;
  event_handler_ = nullptr;
  event_handler_ended_ = false;
  y_axis_is_reversed_ = y_axis_reversed;
  y_size_ = y_canvas_size;
  window_name_ = name;
  window_id_ = nr_created_windows_;
  // Set up polygon buffering.
  points_ = new SVPolyLineBuffer;
  points_->empty = true;

  svmap_mu->lock();
  svmap[window_id_] = this;
  svmap_mu->unlock();

  for (auto &i : event_table_) {
    i = nullptr;
  }

  semaphore_ = new SVSemaphore();

  // Set up an actual Window on the client side.
  char message[kMaxMsgSize];
  snprintf(message, sizeof(message),
           "w%u = luajava.newInstance('com.google.scrollview.ui"
           ".SVWindow','%s',%u,%u,%u,%u,%u,%u,%u)\n",
           window_id_, window_name_, window_id_, x_pos, y_pos, x_size, y_size, x_canvas_size,
           y_canvas_size);
  SendRawMessage(message);

  std::thread t(&ScrollView::StartEventHandler, this);
  t.detach();
}