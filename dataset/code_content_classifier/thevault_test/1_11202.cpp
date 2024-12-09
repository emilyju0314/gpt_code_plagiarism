int StringRenderer::RenderToImage(const char *text, int text_length, Image *pix) {
  if (pix && *pix) {
    pix->destroy();
  }
  InitPangoCairo();

  const int page_offset = FindFirstPageBreakOffset(text, text_length);
  if (!page_offset) {
    return 0;
  }
  start_box_ = boxchars_.size();

  if (!vertical_text_) {
    // Translate by the specified margin
    cairo_translate(cr_, h_margin_, v_margin_);
  } else {
    // Vertical text rendering is achieved by a two-step process of first
    // performing regular horizontal layout with character orientation set to
    // EAST, and then translating and rotating the layout before rendering onto
    // the desired image surface. The settings required for the former step are
    // done within InitPangoCairo().
    //
    // Translate to the top-right margin of page
    cairo_translate(cr_, page_width_ - h_margin_, v_margin_);
    // Rotate the layout
    double rotation = -pango_gravity_to_rotation(
        pango_context_get_base_gravity(pango_layout_get_context(layout_)));
    tlog(2, "Rotating by %f radians\n", rotation);
    cairo_rotate(cr_, rotation);
    pango_cairo_update_layout(cr_, layout_);
  }
  std::string page_text(text, page_offset);
  if (render_fullwidth_latin_) {
    // Convert Basic Latin to their fullwidth forms.
    page_text = ConvertBasicLatinToFullwidthLatin(page_text);
  }
  if (strip_unrenderable_words_) {
    StripUnrenderableWords(&page_text);
  }
  if (drop_uncovered_chars_ && !font_.CoversUTF8Text(page_text.c_str(), page_text.length())) {
    int num_dropped = font_.DropUncoveredChars(&page_text);
    if (num_dropped) {
      tprintf("WARNING: Dropped %d uncovered characters\n", num_dropped);
    }
  }
  if (add_ligatures_) {
    // Add ligatures wherever possible, including custom ligatures.
    page_text = LigatureTable::Get()->AddLigatures(page_text, &font_);
  }
  if (underline_start_prob_ > 0) {
    SetWordUnderlineAttributes(page_text);
  }

  pango_layout_set_text(layout_, page_text.c_str(), page_text.length());

  if (pix) {
    // Set a white background for the target image surface.
    cairo_set_source_rgb(cr_, 1.0, 1.0, 1.0); // sets drawing colour to white
    // Fill the surface with the active colour (if you don't do this, you will
    // be given a surface with a transparent background to draw on)
    cairo_paint(cr_);
    // Set the ink color to black
    cairo_set_source_rgb(cr_, pen_color_[0], pen_color_[1], pen_color_[2]);
    // If the target surface or transformation properties of the cairo instance
    // have changed, update the pango layout to reflect this
    pango_cairo_update_layout(cr_, layout_);
    {
      DISABLE_HEAP_LEAK_CHECK; // for Fontconfig
      // Draw the pango layout onto the cairo surface
      pango_cairo_show_layout(cr_, layout_);
    }
    *pix = CairoARGB32ToPixFormat(surface_);
  }
  ComputeClusterBoxes();
  FreePangoCairo();
  // Update internal state variables.
  ++page_;
  return page_offset;
}