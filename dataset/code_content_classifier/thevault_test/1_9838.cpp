BOOL
OnCreate(HWND hwnd, LPCREATESTRUCT lpcs) {
  DWM_THUMBNAIL_PROPERTIES props = {};
  HWND hwndTarget = *reinterpret_cast<HWND*>(lpcs->lpCreateParams);

  props.rcSource.left = 0;
  props.rcSource.top = 0;
  props.rcSource.right = 1920;
  props.rcSource.bottom = 1080;
  
  // hwndTarget = (HWND)0x00060778;
  DwmRegisterThumbnail(hwnd, hwndTarget, &g_hthumb);
  props.dwFlags = DWM_TNP_VISIBLE | DWM_TNP_RECTSOURCE |
                  DWM_TNP_RECTDESTINATION;
  props.rcDestination = props.rcSource;
  OffsetRect(&props.rcSource,
             -props.rcSource.left, -props.rcSource.top);
  props.fVisible = TRUE;
  DwmUpdateThumbnailProperties(g_hthumb, &props);
  return TRUE;
}