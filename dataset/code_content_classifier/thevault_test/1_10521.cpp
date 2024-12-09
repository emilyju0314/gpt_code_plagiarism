void Tesseract::process_image_event( // action in image win
    const SVEvent &event) {
  // The following variable should remain static, since it is used by
  // debug editor, which uses a single Tesseract instance.
  static ICOORD down;
  ICOORD up;
  TBOX selection_box;
  char msg[80];

  switch (event.type) {
    case SVET_SELECTION:
      if (event.type == SVET_SELECTION) {
        down.set_x(event.x + event.x_size);
        down.set_y(event.y + event.y_size);
        if (mode == SHOW_POINT_CMD_EVENT) {
          show_point(current_page_res, event.x, event.y);
        }
      }

      up.set_x(event.x);
      up.set_y(event.y);

      selection_box = TBOX(down, up);

      switch (mode) {
        case CHANGE_DISP_CMD_EVENT:
          process_selected_words(current_page_res, selection_box,
                                 &tesseract::Tesseract::word_blank_and_set_display);
          break;
        case DUMP_WERD_CMD_EVENT:
          process_selected_words(current_page_res, selection_box,
                                 &tesseract::Tesseract::word_dumper);
          break;
        case SHOW_BLN_WERD_CMD_EVENT:
          process_selected_words(current_page_res, selection_box,
                                 &tesseract::Tesseract::word_bln_display);
          break;
        case DEBUG_WERD_CMD_EVENT:
          debug_word(current_page_res, selection_box);
          break;
        case SHOW_POINT_CMD_EVENT:
          break; // ignore up event

        case RECOG_WERDS:
#  ifndef DISABLED_LEGACY_ENGINE
          image_win->AddMessage("Recogging selected words");
          this->process_selected_words(current_page_res, selection_box,
                                       &Tesseract::recog_interactive);
#  endif // ndef DISABLED_LEGACY_ENGINE
          break;
        case RECOG_PSEUDO:
          image_win->AddMessage("Recogging selected blobs");
          recog_pseudo_word(current_page_res, selection_box);
          break;
        case SHOW_BLOB_FEATURES:
          blob_feature_display(current_page_res, selection_box);
          break;

        default:
          sprintf(msg, "Mode %d not yet implemented", mode);
          image_win->AddMessage(msg);
          break;
      }
    default:
      break;
  }
}