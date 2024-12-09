static void mods_to_e_keysym( UInt32 mods )
{
  if ( mods & cmdKey ) Fl::e_keysym = FL_Meta_L;
  else if ( mods & kEventKeyModifierNumLockMask ) Fl::e_keysym = FL_Num_Lock;
  else if ( mods & optionKey ) Fl::e_keysym = FL_Alt_L;
  else if ( mods & rightOptionKey ) Fl::e_keysym = FL_Alt_R;
  else if ( mods & controlKey ) Fl::e_keysym = FL_Control_L;
  else if ( mods & rightControlKey ) Fl::e_keysym = FL_Control_R;
  else if ( mods & shiftKey ) Fl::e_keysym = FL_Shift_L;
  else if ( mods & rightShiftKey ) Fl::e_keysym = FL_Shift_R;
  else if ( mods & alphaLock ) Fl::e_keysym = FL_Caps_Lock;
  else Fl::e_keysym = 0;
  //printf( "to sym 0x%08x (%04x)\n", Fl::e_keysym, mods );
}