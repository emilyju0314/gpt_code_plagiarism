int Fl::awake(Fl_Awake_Handler func, void *data) {
  int ret = add_awake_handler_(func, data);
  Fl::awake();
  return ret;
}