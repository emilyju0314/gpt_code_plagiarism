bool ReadNextBox(int target_page, int *line_number, FILE *box_file, std::string &utf8_str,
                 TBOX *bounding_box) {
  int page = 0;
  char buff[kBoxReadBufSize]; // boxfile read buffer
  char *buffptr = buff;

  while (fgets(buff, sizeof(buff) - 1, box_file)) {
    (*line_number)++;

    buffptr = buff;
    const auto *ubuf = reinterpret_cast<const unsigned char *>(buffptr);
    if (ubuf[0] == 0xef && ubuf[1] == 0xbb && ubuf[2] == 0xbf) {
      buffptr += 3; // Skip unicode file designation.
    }
    // Check for blank lines in box file
    if (*buffptr == '\n' || *buffptr == '\0') {
      continue;
    }
    // Skip blank boxes.
    if (*buffptr == ' ' || *buffptr == '\t') {
      continue;
    }
    if (*buffptr != '\0') {
      if (!ParseBoxFileStr(buffptr, &page, utf8_str, bounding_box)) {
        tprintf("Box file format error on line %i; ignored\n", *line_number);
        continue;
      }
      if (target_page >= 0 && target_page != page) {
        continue; // Not on the appropriate page.
      }
      return true; // Successfully read a box.
    }
  }
  fclose(box_file);
  return false; // EOF
}