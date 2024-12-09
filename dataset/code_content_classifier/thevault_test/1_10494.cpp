int SampleIterator::SparseCharsetSize() const {
  return charset_map_ != nullptr
             ? charset_map_->SparseSize()
             : (shape_table_ != nullptr ? shape_table_->NumShapes() : sample_set_->charsetsize());
}