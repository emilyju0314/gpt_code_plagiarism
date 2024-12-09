void Tesseract::TrainFromBoxes(const std::vector<TBOX> &boxes, const std::vector<std::string> &texts,
                               BLOCK_LIST *block_list, DocumentData *training_data) {
  auto box_count = boxes.size();
  // Process all the text lines in this page, as defined by the boxes.
  unsigned end_box = 0;
  // Don't let \t, which marks newlines in the box file, get into the line
  // content, as that makes the line unusable in training.
  while (end_box < texts.size() && texts[end_box] == "\t") {
    ++end_box;
  }
  for (auto start_box = end_box; start_box < box_count; start_box = end_box) {
    // Find the textline of boxes starting at start and their bounding box.
    TBOX line_box = boxes[start_box];
    std::string line_str = texts[start_box];
    for (end_box = start_box + 1; end_box < box_count && texts[end_box] != "\t"; ++end_box) {
      line_box += boxes[end_box];
      line_str += texts[end_box];
    }
    // Find the most overlapping block.
    BLOCK *best_block = nullptr;
    int best_overlap = 0;
    BLOCK_IT b_it(block_list);
    for (b_it.mark_cycle_pt(); !b_it.cycled_list(); b_it.forward()) {
      BLOCK *block = b_it.data();
      if (block->pdblk.poly_block() != nullptr && !block->pdblk.poly_block()->IsText()) {
        continue; // Not a text block.
      }
      TBOX block_box = block->pdblk.bounding_box();
      block_box.rotate(block->re_rotation());
      if (block_box.major_overlap(line_box)) {
        TBOX overlap_box = line_box.intersection(block_box);
        if (overlap_box.area() > best_overlap) {
          best_overlap = overlap_box.area();
          best_block = block;
        }
      }
    }
    ImageData *imagedata = nullptr;
    if (best_block == nullptr) {
      tprintf("No block overlapping textline: %s\n", line_str.c_str());
    } else {
      imagedata = GetLineData(line_box, boxes, texts, start_box, end_box, *best_block);
    }
    if (imagedata != nullptr) {
      training_data->AddPageToDocument(imagedata);
    }
    // Don't let \t, which marks newlines in the box file, get into the line
    // content, as that makes the line unusable in training.
    while (end_box < texts.size() && texts[end_box] == "\t") {
      ++end_box;
    }
  }
}