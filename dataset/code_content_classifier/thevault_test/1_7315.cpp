int						// O - TRUE if we handled event
Fl_File_Input::handle(int event) 		// I - Event
{
//  printf("handle(event = %d)\n", event);
  static char inButtonBar = 0;

  switch (event) {
    case FL_MOVE :
    case FL_ENTER :
      if (active_r()) {
	if (Fl::event_y() < (y() + DIR_HEIGHT)) 
          window()->cursor(FL_CURSOR_DEFAULT);
	else 
          window()->cursor(FL_CURSOR_INSERT);
      }

      return 1;

    case FL_PUSH :
      inButtonBar = (Fl::event_y() < (y() + DIR_HEIGHT));
    case FL_RELEASE :
    case FL_DRAG :
      if (inButtonBar) 
        return handle_button(event);
      else
        return Fl_Input::handle(event);

    default :
      { Fl_Widget_Tracker wp(this);
	if (Fl_Input::handle(event)) {
	  if (wp.exists())
	    damage(FL_DAMAGE_BAR);
	  return 1;
	}
      }
      return 0;
  }
}