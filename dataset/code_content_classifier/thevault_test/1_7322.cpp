static int dnd_aware(Window& window) {
  Atom actual; int format; unsigned long count, remaining;
  unsigned char *data = 0;
  XGetWindowProperty(fl_display, window, fl_XdndAware,
		     0, 4, False, XA_ATOM,
		     &actual, &format,
		     &count, &remaining, &data);
  if (actual == XA_ATOM && format==32 && count && data)
    return int(*(Atom*)data);
  return 0;
}