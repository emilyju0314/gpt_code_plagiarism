static void chord_to_e_state( UInt32 chord )
{
  static ulong state[] = 
  { 
    0, FL_BUTTON1, FL_BUTTON3, FL_BUTTON1|FL_BUTTON3, FL_BUTTON2,
    FL_BUTTON2|FL_BUTTON1, FL_BUTTON2|FL_BUTTON3, 
    FL_BUTTON2|FL_BUTTON1|FL_BUTTON3
  };
  Fl::e_state = ( Fl::e_state & 0xff0000 ) | state[ chord & 0x07 ];
}