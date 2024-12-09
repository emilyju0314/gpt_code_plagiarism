int Fl::screen_count() {
  if (!num_screens) screen_init();

  return num_screens;
}