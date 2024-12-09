int TessClassifier::DisplayClassifyAs(const TrainingSample &sample, Image page_pix, int unichar_id,
                                      int index, std::vector<ScrollView *> &windows) {
  int shape_id = unichar_id;
  // TODO(rays) Fix this so it works with both flat and real shapetables.
  //  if (GetShapeTable() != nullptr)
  //  shape_id = BestShapeForUnichar(sample, page_pix, unichar_id, nullptr);
  if (shape_id < 0) {
    return index;
  }
  if (UnusedClassIdIn(classify_->PreTrainedTemplates, shape_id)) {
    tprintf("No built-in templates for class/shape %d\n", shape_id);
    return index;
  }
#ifndef GRAPHICS_DISABLED
  classify_->ShowBestMatchFor(shape_id, sample.features(), sample.num_features());
#endif
  return index;
}