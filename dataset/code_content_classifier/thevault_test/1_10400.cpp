bool ICOORD::DeSerialize(bool swap, FILE *fp) {
  if (!tesseract::DeSerialize(fp, &xcoord)) {
    return false;
  }
  if (!tesseract::DeSerialize(fp, &ycoord)) {
    return false;
  }
  if (swap) {
    ReverseN(&xcoord, sizeof(xcoord));
    ReverseN(&ycoord, sizeof(ycoord));
  }
  return true;
}