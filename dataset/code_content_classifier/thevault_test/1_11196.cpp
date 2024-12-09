int StringRenderer::FindFirstPageBreakOffset(const char *text, int text_length) {
  if (!text_length) {
    return 0;
  }
  const int max_height = (page_height_ - 2 * v_margin_);
  const int max_width = (page_width_ - 2 * h_margin_);
  const int max_layout_height = vertical_text_ ? max_width : max_height;

  UNICHAR::const_iterator it = UNICHAR::begin(text, text_length);
  const UNICHAR::const_iterator it_end = UNICHAR::end(text, text_length);
  const int kMaxUnicodeBufLength = 15000;
  for (int i = 0; i < kMaxUnicodeBufLength && it != it_end; ++it, ++i) {
    ;
  }
  int buf_length = it.utf8_data() - text;
  tlog(1, "len = %d  buf_len = %d\n", text_length, buf_length);
  pango_layout_set_text(layout_, text, buf_length);

  PangoLayoutIter *line_iter = nullptr;
  { // Fontconfig caches some info here that is not freed before exit.
    DISABLE_HEAP_LEAK_CHECK;
    line_iter = pango_layout_get_iter(layout_);
  }
  bool first_page = true;
  int page_top = 0;
  int offset = buf_length;
  do {
    // Get bounding box of the current line
    PangoRectangle line_ink_rect;
    pango_layout_iter_get_line_extents(line_iter, &line_ink_rect, nullptr);
    pango_extents_to_pixels(&line_ink_rect, nullptr);
    PangoLayoutLine *line = pango_layout_iter_get_line_readonly(line_iter);
    if (first_page) {
      page_top = line_ink_rect.y;
      first_page = false;
    }
    int line_bottom = line_ink_rect.y + line_ink_rect.height;
    if (line_bottom - page_top > max_layout_height) {
      offset = line->start_index;
      tlog(1, "Found offset = %d\n", offset);
      break;
    }
  } while (pango_layout_iter_next_line(line_iter));
  pango_layout_iter_free(line_iter);
  return offset;
}