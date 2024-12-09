void
OnPrintClient(HWND hwnd, HDC hdc) {
  PAINTSTRUCT ps;
  ps.hdc = hdc;
  GetClientRect(hwnd, &ps.rcPaint);
  PaintContent(hwnd, &ps);

}