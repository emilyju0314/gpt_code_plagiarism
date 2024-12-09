char *TessBaseAPI::GetWordStrBoxText(int page_number = 0) {
  if (tesseract_ == nullptr || (page_res_ == nullptr && Recognize(nullptr) < 0)) {
    return nullptr;
  }

  std::string wordstr_box_str;
  int left = 0, top = 0, right = 0, bottom = 0;

  bool first_line = true;

  LTRResultIterator *res_it = GetLTRIterator();
  while (!res_it->Empty(RIL_BLOCK)) {
    if (res_it->Empty(RIL_WORD)) {
      res_it->Next(RIL_WORD);
      continue;
    }

    if (res_it->IsAtBeginningOf(RIL_TEXTLINE)) {
      if (!first_line) {
        wordstr_box_str += "\n\t " + std::to_string(right + 1);
        wordstr_box_str += " " + std::to_string(image_height_ - bottom);
        wordstr_box_str += " " + std::to_string(right + 5);
        wordstr_box_str += " " + std::to_string(image_height_ - top);
        wordstr_box_str += " " + std::to_string(page_number); // row for tab for EOL
        wordstr_box_str += "\n";
      } else {
        first_line = false;
      }
      // Use bounding box for whole line for WordStr
      res_it->BoundingBox(RIL_TEXTLINE, &left, &top, &right, &bottom);
      wordstr_box_str += "WordStr " + std::to_string(left);
      wordstr_box_str += " " + std::to_string(image_height_ - bottom);
      wordstr_box_str += " " + std::to_string(right);
      wordstr_box_str += " " + std::to_string(image_height_ - top);
      wordstr_box_str += " " + std::to_string(page_number); // word
      wordstr_box_str += " #";
    }
    do {
      wordstr_box_str += std::unique_ptr<const char[]>(res_it->GetUTF8Text(RIL_WORD)).get();
      wordstr_box_str += " ";
      res_it->Next(RIL_WORD);
    } while (!res_it->Empty(RIL_BLOCK) && !res_it->IsAtBeginningOf(RIL_WORD));
  }

  if (left != 0 && top != 0 && right != 0 && bottom != 0) {
    wordstr_box_str += "\n\t " + std::to_string(right + 1);
    wordstr_box_str += " " + std::to_string(image_height_ - bottom);
    wordstr_box_str += " " + std::to_string(right + 5);
    wordstr_box_str += " " + std::to_string(image_height_ - top);
    wordstr_box_str += " " + std::to_string(page_number); // row for tab for EOL
    wordstr_box_str += "\n";
  }
  char *ret = new char[wordstr_box_str.length() + 1];
  strcpy(ret, wordstr_box_str.c_str());
  delete res_it;
  return ret;
}