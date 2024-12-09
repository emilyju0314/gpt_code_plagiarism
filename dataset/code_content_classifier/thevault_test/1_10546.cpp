int ShapeClassifier::BestShapeForUnichar(const TrainingSample &sample, Image page_pix,
                                         UNICHAR_ID unichar_id, ShapeRating *result) {
  std::vector<ShapeRating> results;
  const ShapeTable *shapes = GetShapeTable();
  int num_results = ClassifySample(sample, page_pix, 0, unichar_id, &results);
  for (int r = 0; r < num_results; ++r) {
    if (shapes->GetShape(results[r].shape_id).ContainsUnichar(unichar_id)) {
      if (result != nullptr) {
        *result = results[r];
      }
      return results[r].shape_id;
    }
  }
  return -1;
}