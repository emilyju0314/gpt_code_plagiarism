bool IntFeatureSpace::Serialize(FILE *fp) const {
  if (fwrite(&x_buckets_, sizeof(x_buckets_), 1, fp) != 1) {
    return false;
  }
  if (fwrite(&y_buckets_, sizeof(y_buckets_), 1, fp) != 1) {
    return false;
  }
  if (fwrite(&theta_buckets_, sizeof(theta_buckets_), 1, fp) != 1) {
    return false;
  }
  return true;
}