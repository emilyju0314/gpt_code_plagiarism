double DetLineFit::Fit(float *m, float *c) {
  ICOORD start, end;
  double error = Fit(&start, &end);
  if (end.x() != start.x()) {
    *m = static_cast<float>(end.y() - start.y()) / (end.x() - start.x());
    *c = start.y() - *m * start.x();
  } else {
    *m = 0.0f;
    *c = 0.0f;
  }
  return error;
}