void ShapeClassifier::FilterDuplicateUnichars(std::vector<ShapeRating> *results) const {
  std::vector<ShapeRating> filtered_results;
  // Copy results to filtered results and knock out duplicate unichars.
  const ShapeTable *shapes = GetShapeTable();
  for (unsigned r = 0; r < results->size(); ++r) {
    if (r > 0) {
      const Shape &shape_r = shapes->GetShape((*results)[r].shape_id);
      int c;
      for (c = 0; c < shape_r.size(); ++c) {
        int unichar_id = shape_r[c].unichar_id;
        unsigned s;
        for (s = 0; s < r; ++s) {
          const Shape &shape_s = shapes->GetShape((*results)[s].shape_id);
          if (shape_s.ContainsUnichar(unichar_id)) {
            break; // We found unichar_id.
          }
        }
        if (s == r) {
          break; // We didn't find unichar_id.
        }
      }
      if (c == shape_r.size()) {
        continue; // We found all the unichar ids in previous answers.
      }
    }
    filtered_results.push_back((*results)[r]);
  }
  *results = filtered_results;
}