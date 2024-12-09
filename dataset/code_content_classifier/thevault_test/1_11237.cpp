SVPaint::SVPaint(const char *server_name) {
  window_ = new ScrollView("ScrollView Paint Example", // window caption
                           0, 0,                       // x,y window position
                           500, 500,                   // window size
                           500, 500,                   // canvas size
                           false,                      // whether the Y axis is inversed.
                                                       // this is included due to legacy
                                                       // reasons for tesseract and enables
                                                       // us to have (0,0) as the LOWER left
                                                       // of the coordinate system.
                           server_name);               // the server address.

  // Set the start modes to point-to-point and line drawing.
  click_mode_ = 1;
  drag_mode_ = 4;
  has_start_point_ = false;

  // Bild our menus and add them to the window. The flag illustrates whether
  // this is a menu bar.
  SVMenuNode *popup_menu = BuildPopupMenu();
  popup_menu->BuildMenu(window_, false);

  SVMenuNode *bar_menu = BuildMenuBar();
  bar_menu->BuildMenu(window_, true);

  // Set the initial color values to White (could also be done by
  // passing (rgb[0], rgb[1], rgb[2]).
  window_->Pen(ScrollView::WHITE);
  window_->Brush(ScrollView::WHITE);

  // Adds the event handler to the window. This actually ensures that Notify
  // gets called when events occur.
  window_->AddEventHandler(this);

  // Set the window visible (calling this is important to actually render
  // everything. Without this call, the window would also be drawn, but the
  // menu bars would be missing.
  window_->SetVisible(true);

  // Rest this thread until its window is destroyed.
  // Note that a special eventhandling thread was created when constructing
  // the window. Due to this, the application will not deadlock here.
  window_->AwaitEvent(SVET_DESTROY);
  // We now have 3 Threads running:
  // (1) The MessageReceiver thread which fetches messages and distributes them
  // (2) The EventHandler thread which handles all events for window_
  // (3) The main thread which waits on window_ for a DESTROY event (blocked)
}