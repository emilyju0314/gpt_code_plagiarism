void SampleIterator::Next() {
  if (shape_table_ != nullptr) {
    // Next sample in this class/font combination.
    ++sample_index_;
    if (sample_index_ < num_samples_) {
      return;
    }
    // Next font in this class in this shape.
    sample_index_ = 0;
    do {
      ++shape_font_index_;
      if (shape_font_index_ >= num_shape_fonts_) {
        // Next unichar in this shape.
        shape_font_index_ = 0;
        ++shape_char_index_;
        if (shape_char_index_ >= num_shape_chars_) {
          // Find the next shape that is mapped in the charset_map_.
          shape_char_index_ = 0;
          do {
            ++shape_index_;
          } while (shape_index_ < num_shapes_ && charset_map_ != nullptr &&
                   charset_map_->SparseToCompact(shape_index_) < 0);
          if (shape_index_ >= num_shapes_) {
            return; // The end.
          }
          num_shape_chars_ = shape_table_->GetShape(shape_index_).size();
        }
      }
      const UnicharAndFonts *shape_entry = GetShapeEntry();
      num_shape_fonts_ = shape_entry->font_ids.size();
      int char_id = shape_entry->unichar_id;
      int font_id = shape_entry->font_ids[shape_font_index_];
      num_samples_ = sample_set_->NumClassSamples(font_id, char_id, randomize_);
    } while (num_samples_ == 0);
  } else {
    // We are just iterating over the samples.
    ++shape_index_;
  }
}