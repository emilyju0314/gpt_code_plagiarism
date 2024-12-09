int ShapeClassifier::UnicharClassifySample(const TrainingSample &sample, Image page_pix, int debug,
                                           UNICHAR_ID keep_this,
                                           std::vector<UnicharRating> *results) {
  results->clear();
  std::vector<ShapeRating> shape_results;
  int num_shape_results = ClassifySample(sample, page_pix, debug, keep_this, &shape_results);
  const ShapeTable *shapes = GetShapeTable();
  std::vector<int> unichar_map(shapes->unicharset().size(), -1);
  for (int r = 0; r < num_shape_results; ++r) {
    shapes->AddShapeToResults(shape_results[r], &unichar_map, results);
  }
  return results->size();
}