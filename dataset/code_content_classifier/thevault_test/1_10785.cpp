int TextlineProjection::EvaluateColPartition(const ColPartition &part, const DENORM *denorm,
                                             bool debug) const {
  if (part.IsSingleton()) {
    return EvaluateBox(part.bounding_box(), denorm, debug);
  }
  // Test vertical orientation.
  TBOX box = part.bounding_box();
  // Use the partition median for left/right.
  box.set_left(part.median_left());
  box.set_right(part.median_right());
  int vresult = EvaluateBox(box, denorm, debug);

  // Test horizontal orientation.
  box = part.bounding_box();
  // Use the partition median for top/bottom.
  box.set_top(part.median_top());
  box.set_bottom(part.median_bottom());
  int hresult = EvaluateBox(box, denorm, debug);
  if (debug) {
    tprintf("Partition hresult=%d, vresult=%d from:", hresult, vresult);
    part.bounding_box().print();
    part.Print();
  }
  return hresult >= -vresult ? hresult : vresult;
}