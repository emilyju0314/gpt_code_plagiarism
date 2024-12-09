void
OnPaint(HWND hwnd) {
  PAINTSTRUCT ps;
  BeginPaint(hwnd, &ps);
  PaintContent(hwnd, &ps);
  EndPaint(hwnd, &ps);
}