void AsciiToRowInfo(const char *text, int row_number, RowInfo *info) {
  const int kCharWidth = 10;
  const int kLineSpace = 30;
  info->text = text;
  info->has_leaders = strstr(text, "...") != nullptr || strstr(text, ". . .") != nullptr;
  info->has_drop_cap = false;
  info->pix_ldistance = info->pix_rdistance = 0;
  info->average_interword_space = kCharWidth;
  info->pix_xheight = kCharWidth;
  info->lword_text = info->rword_text = "";
  info->ltr = true;

  std::vector<std::string> words = split(text, ' ');
  info->num_words = words.size();
  if (info->num_words < 1) {
    return;
  }

  info->lword_text = words[0].c_str();
  info->rword_text = words[words.size() - 1].c_str();
  int lspace = 0;
  while (lspace < info->text.size() && text[lspace] == ' ') {
    lspace++;
  }
  int rspace = 0;
  while (rspace < info->text.size() && text[info->text.size() - rspace - 1] == ' ') {
    rspace++;
  }

  int top = -kLineSpace * row_number;
  int bottom = top - kLineSpace;
  int row_right = kCharWidth * info->text.size();
  int lword_width = kCharWidth * info->lword_text.size();
  int rword_width = kCharWidth * info->rword_text.size();
  info->pix_ldistance = lspace * kCharWidth;
  info->pix_rdistance = rspace * kCharWidth;
  info->lword_box = TBOX(info->pix_ldistance, bottom, info->pix_ldistance + lword_width, top);
  info->rword_box = TBOX(row_right - info->pix_rdistance - rword_width, bottom,
                         row_right - info->pix_rdistance, top);
  LeftWordAttributes(nullptr, nullptr, info->lword_text, &info->lword_indicates_list_item,
                     &info->lword_likely_starts_idea, &info->lword_likely_ends_idea);
  RightWordAttributes(nullptr, nullptr, info->rword_text, &info->rword_indicates_list_item,
                      &info->rword_likely_starts_idea, &info->rword_likely_ends_idea);
}