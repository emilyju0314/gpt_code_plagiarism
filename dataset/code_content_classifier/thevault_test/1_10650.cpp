bool Tesseract::TrainLineRecognizer(const char *input_imagename, const std::string &output_basename,
                                    BLOCK_LIST *block_list) {
  std::string lstmf_name = output_basename + ".lstmf";
  DocumentData images(lstmf_name);
  if (applybox_page > 0) {
    // Load existing document for the previous pages.
    if (!images.LoadDocument(lstmf_name.c_str(), 0, 0, nullptr)) {
      tprintf("Failed to read training data from %s!\n", lstmf_name.c_str());
      return false;
    }
  }
  std::vector<TBOX> boxes;
  std::vector<std::string> texts;
  // Get the boxes for this page, if there are any.
  if (!ReadAllBoxes(applybox_page, false, input_imagename, &boxes, &texts, nullptr, nullptr) ||
      boxes.empty()) {
    tprintf("Failed to read boxes from %s\n", input_imagename);
    return false;
  }
  TrainFromBoxes(boxes, texts, block_list, &images);
  if (images.PagesSize() == 0) {
    tprintf("Failed to read pages from %s\n", input_imagename);
    return false;
  }
  images.Shuffle();
  if (!images.SaveDocument(lstmf_name.c_str(), nullptr)) {
    tprintf("Failed to write training data to %s!\n", lstmf_name.c_str());
    return false;
  }
  return true;
}