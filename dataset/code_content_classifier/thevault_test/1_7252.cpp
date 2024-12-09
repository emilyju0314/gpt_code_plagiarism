int fl_ready()
{
  EventRef event;
  return !ReceiveNextEvent(0, NULL, 0.0, false, &event);
}