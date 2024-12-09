bool SEAM::IsHealthy(const TBLOB &blob, int min_points, int min_area) const {
  // TODO(rays) Try testing all the splits. Duplicating original code for now,
  // which tested only the first.
  return num_splits_ == 0 || splits_[0].IsHealthy(blob, min_points, min_area);
}