static int keycode_wrap_old(
                char * buffer,
                int, EventKind, UInt32, // not used in this function
                UInt32, UInt32 *,       // not used in this function
                unsigned char key,
                unsigned short sym)
{
  if ( (sym >= FL_KP && sym <= FL_KP_Last) || !(sym & 0xff00) ||
        sym == FL_Tab || sym == FL_Enter) {
    buffer[0] = key;
    return 1;
  } else {
    buffer[0] = 0;
    return 0;
  }
}