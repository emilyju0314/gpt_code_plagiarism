void PGEventHandler::Notify(const SVEvent *event) {
  char myval = '0';
  if (event->type == SVET_POPUP) {
    pe->Notify(event);
  } // These are handled by ParamsEditor
  else if (event->type == SVET_EXIT) {
    stillRunning = false;
  } else if (event->type == SVET_MENU) {
    if (strcmp(event->parameter, "true") == 0) {
      myval = 'T';
    } else if (strcmp(event->parameter, "false") == 0) {
      myval = 'F';
    }
    tess_->process_cmd_win_event(event->command_id, &myval);
  } else {
    tess_->process_image_event(*event);
  }
}