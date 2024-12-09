void
OnDestroy(HWND hwnd) {
  if (g_hthumb) { DwmUnregisterThumbnail(g_hthumb); }
  PostQuitMessage(0);
}