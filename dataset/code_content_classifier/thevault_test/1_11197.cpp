bool StringRenderer::GetClusterStrings(std::vector<std::string> *cluster_text) {
  std::map<int, std::string> start_byte_to_text;
  PangoLayoutIter *run_iter = pango_layout_get_iter(layout_);
  const char *full_text = pango_layout_get_text(layout_);
  do {
    PangoLayoutRun *run = pango_layout_iter_get_run_readonly(run_iter);
    if (!run) {
      // End of line nullptr run marker
      tlog(2, "Found end of line marker\n");
      continue;
    }
    PangoGlyphItemIter cluster_iter;
    gboolean have_cluster;
    for (have_cluster = pango_glyph_item_iter_init_start(&cluster_iter, run, full_text);
         have_cluster; have_cluster = pango_glyph_item_iter_next_cluster(&cluster_iter)) {
      const int start_byte_index = cluster_iter.start_index;
      const int end_byte_index = cluster_iter.end_index;
      std::string text =
          std::string(full_text + start_byte_index, end_byte_index - start_byte_index);
      if (IsUTF8Whitespace(text.c_str())) {
        tlog(2, "Found whitespace\n");
        text = " ";
      }
      tlog(2, "start_byte=%d end_byte=%d : '%s'\n", start_byte_index, end_byte_index, text.c_str());
      if (add_ligatures_) {
        // Make sure the output box files have ligatured text in case the font
        // decided to use an unmapped glyph.
        text = LigatureTable::Get()->AddLigatures(text, nullptr);
      }
      start_byte_to_text[start_byte_index] = text;
    }
  } while (pango_layout_iter_next_run(run_iter));
  pango_layout_iter_free(run_iter);

  cluster_text->clear();
  for (auto it = start_byte_to_text.begin(); it != start_byte_to_text.end(); ++it) {
    cluster_text->push_back(it->second);
  }
  return !cluster_text->empty();
}