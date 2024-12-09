void SampleIterator::Init(const IndexMapBiDi *charset_map, const ShapeTable *shape_table,
                          bool randomize, TrainingSampleSet *sample_set) {
  Clear();
  charset_map_ = charset_map;
  shape_table_ = shape_table;
  sample_set_ = sample_set;
  randomize_ = randomize;
  if (shape_table_ == nullptr && charset_map_ != nullptr) {
    // The caller wishes to iterate by class. The easiest way to do this
    // is to create a dummy shape_table_ that we will own.
    int num_fonts = sample_set_->NumFonts();
    owned_shape_table_ = new ShapeTable(sample_set_->unicharset());
    int charsetsize = sample_set_->unicharset().size();
    for (int c = 0; c < charsetsize; ++c) {
      // We always add a shape for each character to keep the index in sync
      // with the unichar_id.
      int shape_id = owned_shape_table_->AddShape(c, 0);
      for (int f = 1; f < num_fonts; ++f) {
        if (sample_set_->NumClassSamples(f, c, true) > 0) {
          owned_shape_table_->AddToShape(shape_id, c, f);
        }
      }
    }
    shape_table_ = owned_shape_table_;
  }
  if (shape_table_ != nullptr) {
    num_shapes_ = shape_table_->NumShapes();
  } else {
    num_shapes_ = randomize ? sample_set_->num_samples() : sample_set_->num_raw_samples();
  }
  Begin();
}