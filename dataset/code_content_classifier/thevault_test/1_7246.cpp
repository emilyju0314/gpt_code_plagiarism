static unsigned int mods_to_e_state( UInt32 mods )
{
  long state = 0;
  if ( mods & kEventKeyModifierNumLockMask ) state |= FL_NUM_LOCK;
  if ( mods & cmdKey ) state |= FL_META;
  if ( mods & (optionKey|rightOptionKey) ) state |= FL_ALT;
  if ( mods & (controlKey|rightControlKey) ) state |= FL_CTRL;
  if ( mods & (shiftKey|rightShiftKey) ) state |= FL_SHIFT;
  if ( mods & alphaLock ) state |= FL_CAPS_LOCK;
  unsigned int ret = ( Fl::e_state & 0xff000000 ) | state;
  Fl::e_state = ret;
  //printf( "State 0x%08x (%04x)\n", Fl::e_state, mods );
  return ret;
}