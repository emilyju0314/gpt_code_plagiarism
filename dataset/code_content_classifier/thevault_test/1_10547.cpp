void ShapeClassifier::DebugDisplay(const TrainingSample &sample, Image page_pix,
                                   UNICHAR_ID unichar_id) {
  static ScrollView *terminator = nullptr;
  if (terminator == nullptr) {
    terminator = new ScrollView("XIT", 0, 0, 50, 50, 50, 50, true);
  }
  ScrollView *debug_win = CreateFeatureSpaceWindow("ClassifierDebug", 0, 0);
  // Provide a right-click menu to choose the class.
  auto *popup_menu = new SVMenuNode();
  popup_menu->AddChild("Choose class to debug", 0, "x", "Class to debug");
  popup_menu->BuildMenu(debug_win, false);
  // Display the features in green.
  const INT_FEATURE_STRUCT *features = sample.features();
  uint32_t num_features = sample.num_features();
  for (uint32_t f = 0; f < num_features; ++f) {
    RenderIntFeature(debug_win, &features[f], ScrollView::GREEN);
  }
  debug_win->Update();
  std::vector<UnicharRating> results;
  // Debug classification until the user quits.
  const UNICHARSET &unicharset = GetUnicharset();
  SVEvent *ev;
  SVEventType ev_type;
  do {
    std::vector<ScrollView *> windows;
    if (unichar_id >= 0) {
      tprintf("Debugging class %d = %s\n", unichar_id, unicharset.id_to_unichar(unichar_id));
      UnicharClassifySample(sample, page_pix, 1, unichar_id, &results);
      DisplayClassifyAs(sample, page_pix, unichar_id, 1, windows);
    } else {
      tprintf("Invalid unichar_id: %d\n", unichar_id);
      UnicharClassifySample(sample, page_pix, 1, -1, &results);
    }
    if (unichar_id >= 0) {
      tprintf("Debugged class %d = %s\n", unichar_id, unicharset.id_to_unichar(unichar_id));
    }
    tprintf("Right-click in ClassifierDebug window to choose debug class,");
    tprintf(" Left-click or close window to quit...\n");
    UNICHAR_ID old_unichar_id;
    do {
      old_unichar_id = unichar_id;
      ev = debug_win->AwaitEvent(SVET_ANY);
      ev_type = ev->type;
      if (ev_type == SVET_POPUP) {
        if (unicharset.contains_unichar(ev->parameter)) {
          unichar_id = unicharset.unichar_to_id(ev->parameter);
        } else {
          tprintf("Char class '%s' not found in unicharset", ev->parameter);
        }
      }
      delete ev;
    } while (unichar_id == old_unichar_id && ev_type != SVET_CLICK && ev_type != SVET_DESTROY);
    for (auto window : windows) {
      delete window;
    }
  } while (ev_type != SVET_CLICK && ev_type != SVET_DESTROY);
  delete debug_win;
}