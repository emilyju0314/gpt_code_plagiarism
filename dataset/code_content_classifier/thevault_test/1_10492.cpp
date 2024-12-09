int SampleIterator::GlobalSampleIndex() const {
  if (shape_table_ != nullptr) {
    const UnicharAndFonts *shape_entry = GetShapeEntry();
    int char_id = shape_entry->unichar_id;
    int font_id = shape_entry->font_ids[shape_font_index_];
    return sample_set_->GlobalSampleIndex(font_id, char_id, sample_index_);
  } else {
    return shape_index_;
  }
}