ftgl::texture_glyph_t* TextRenderer::MaybeLoadAndGetGlyph(ftgl::texture_font_t* font,
                                                          const char* character) {
  if (!texture_font_find_glyph(font, character)) {
    texture_font_load_glyph(font, character);
    texture_atlas_changed_ = true;
  }

  return texture_font_get_glyph(font, character);
}