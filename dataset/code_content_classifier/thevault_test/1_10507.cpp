void Tesseract::recog_training_segmented(const char *filename, PAGE_RES *page_res,
                                         volatile ETEXT_DESC *monitor, FILE *output_file) {
  std::string box_fname = filename;
  const char *lastdot = strrchr(box_fname.c_str(), '.');
  if (lastdot != nullptr) {
    box_fname[lastdot - box_fname.c_str()] = '\0';
  }
  box_fname += ".box";
  // ReadNextBox() will close box_file
  FILE *box_file = fopen(box_fname.c_str(), "r");
  if (box_file == nullptr) {
    tprintf("Error: Could not open file %s\n", box_fname.c_str());
    ASSERT_HOST(box_file);
  }

  PAGE_RES_IT page_res_it;
  page_res_it.page_res = page_res;
  page_res_it.restart_page();
  std::string label;

  // Process all the words on this page.
  TBOX tbox; // tesseract-identified box
  TBOX bbox; // box from the box file
  bool keep_going;
  int line_number = 0;
  int examined_words = 0;
  do {
    keep_going = read_t(&page_res_it, &tbox);
    keep_going &= ReadNextBox(applybox_page, &line_number, box_file, label, &bbox);
    // Align bottom left points of the TBOXes.
    while (keep_going && !NearlyEqual<int>(tbox.bottom(), bbox.bottom(), kMaxBoxEdgeDiff)) {
      if (bbox.bottom() < tbox.bottom()) {
        page_res_it.forward();
        keep_going = read_t(&page_res_it, &tbox);
      } else {
        keep_going = ReadNextBox(applybox_page, &line_number, box_file, label, &bbox);
      }
    }
    while (keep_going && !NearlyEqual<int>(tbox.left(), bbox.left(), kMaxBoxEdgeDiff)) {
      if (bbox.left() > tbox.left()) {
        page_res_it.forward();
        keep_going = read_t(&page_res_it, &tbox);
      } else {
        keep_going = ReadNextBox(applybox_page, &line_number, box_file, label, &bbox);
      }
    }
    // OCR the word if top right points of the TBOXes are similar.
    if (keep_going && NearlyEqual<int>(tbox.right(), bbox.right(), kMaxBoxEdgeDiff) &&
        NearlyEqual<int>(tbox.top(), bbox.top(), kMaxBoxEdgeDiff)) {
      ambigs_classify_and_output(label.c_str(), &page_res_it, output_file);
      examined_words++;
    }
    page_res_it.forward();
  } while (keep_going);

  // Set up scripts on all of the words that did not get sent to
  // ambigs_classify_and_output.  They all should have, but if all the
  // werd_res's don't get uch_sets, tesseract will crash when you try
  // to iterate over them. :-(
  int total_words = 0;
  for (page_res_it.restart_page(); page_res_it.block() != nullptr; page_res_it.forward()) {
    if (page_res_it.word()) {
      if (page_res_it.word()->uch_set == nullptr) {
        page_res_it.word()->SetupFake(unicharset);
      }
      total_words++;
    }
  }
  if (examined_words < 0.85 * total_words) {
    tprintf(
        "TODO(antonova): clean up recog_training_segmented; "
        " It examined only a small fraction of the ambigs image.\n");
  }
  tprintf("recog_training_segmented: examined %d / %d words.\n", examined_words, total_words);
}