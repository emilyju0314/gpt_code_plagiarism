int fl_wait(double time_to_wait) {
  int have_message = 0;

  run_checks();

  // idle processing
  static char in_idle;
  if (Fl::idle && !in_idle) {
    in_idle = 1;
    Fl::idle();
    in_idle = 0;
  }
  
  if (nfds) {
    // For WIN32 we need to poll for socket input FIRST, since
    // the event queue is not something we can select() on...
    timeval t;
    t.tv_sec = 0;
    t.tv_usec = 0;

    fd_set fdt[3];
    memcpy(fdt, fdsets, sizeof fdt); // one shot faster fdt init
    if (get_wsock_mod()&& s_wsock_select(maxfd+1,&fdt[0],&fdt[1],&fdt[2],&t)) {
      // We got something - do the callback!
      for (int i = 0; i < nfds; i ++) {
	SOCKET f = fd[i].fd;
	short revents = 0;
	if (fl_wsk_fd_is_set(f, &fdt[0])) revents |= FL_READ;
	if (fl_wsk_fd_is_set(f, &fdt[1])) revents |= FL_WRITE;
	if (fl_wsk_fd_is_set(f, &fdt[2])) revents |= FL_EXCEPT;
	if (fd[i].events & revents) fd[i].cb(f, fd[i].arg);
      }
      time_to_wait = 0.0; // just peek for any messages
    } else {
      // we need to check them periodically, so set a short timeout:
      if (time_to_wait > .001) time_to_wait = .001;
    }
  }

  if (Fl::idle || Fl::damage()) 
    time_to_wait = 0.0;

  // if there are no more windows and this timer is set
  // to FOREVER, continue through or look up indefinitely
  if (!Fl::first_window() && time_to_wait==1e20)
    time_to_wait = 0.0;

  fl_unlock_function();

  time_to_wait = (time_to_wait > 10000 ? 10000 : time_to_wait);
  int t_msec = (int) (time_to_wait * 1000.0 + 0.5);
  MsgWaitForMultipleObjects(0, NULL, FALSE, t_msec, QS_ALLINPUT);

  fl_lock_function();

  // Execute the message we got, and all other pending messages:
  // have_message = PeekMessage(&fl_msg, NULL, 0, 0, PM_REMOVE);
  have_message = PeekMessageW(&fl_msg, NULL, 0, 0, PM_REMOVE);
  if (have_message > 0) {
    while (have_message != 0 && have_message != -1) {
      if (fl_msg.message == fl_wake_msg) {
        // Used for awaking wait() from another thread
	thread_message_ = (void*)fl_msg.wParam;
        Fl_Awake_Handler func;
        void *data;
        while (Fl::get_awake_handler_(func, data)==0) {
          func(data);
        }
      }

      TranslateMessage(&fl_msg);
      DispatchMessageW(&fl_msg);
      have_message = PeekMessageW(&fl_msg, NULL, 0, 0, PM_REMOVE);
    }
  }
  Fl::flush();

  // This should return 0 if only timer events were handled:
  return 1;
}