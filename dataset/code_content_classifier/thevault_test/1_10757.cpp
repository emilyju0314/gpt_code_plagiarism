void ScrollView::SendMsg(const char *format, ...) {
  if (!points_->empty) {
    SendPolygon();
  }
  va_list args;
  char message[kMaxMsgSize - 4];

  va_start(args, format); // variable list
  vsnprintf(message, sizeof(message), format, args);
  va_end(args);

  char form[kMaxMsgSize];
  snprintf(form, sizeof(form), "w%u:%s\n", window_id_, message);

  stream_->Send(form);
}