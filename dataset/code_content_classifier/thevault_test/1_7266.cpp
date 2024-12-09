void Fl_Window::size_range_() {
  size_range_set = 1;
  HISize minSize = { minw, minh };
  HISize maxSize = { maxw?maxw:32000, maxh?maxh:32000 };
  if (i && i->xid)
    SetWindowResizeLimits(i->xid, &minSize, &maxSize);
}