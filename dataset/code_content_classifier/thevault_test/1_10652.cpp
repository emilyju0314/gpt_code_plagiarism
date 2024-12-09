ImageData *Tesseract::GetLineData(const TBOX &line_box, const std::vector<TBOX> &boxes,
                                  const std::vector<std::string> &texts, int start_box, int end_box,
                                  const BLOCK &block) {
  TBOX revised_box;
  ImageData *image_data = GetRectImage(line_box, block, kImagePadding, &revised_box);
  if (image_data == nullptr) {
    return nullptr;
  }
  image_data->set_page_number(applybox_page);
  // Copy the boxes and shift them so they are relative to the image.
  FCOORD block_rotation(block.re_rotation().x(), -block.re_rotation().y());
  ICOORD shift = -revised_box.botleft();
  std::vector<TBOX> line_boxes;
  std::vector<std::string> line_texts;
  for (int b = start_box; b < end_box; ++b) {
    TBOX box = boxes[b];
    box.rotate(block_rotation);
    box.move(shift);
    line_boxes.push_back(box);
    line_texts.push_back(texts[b]);
  }
  std::vector<int> page_numbers(line_boxes.size(), applybox_page);
  image_data->AddBoxes(line_boxes, line_texts, page_numbers);
  return image_data;
}