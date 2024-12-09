int Fl::x() {
  BitMap r;
  GetQDGlobalsScreenBits(&r);
  return r.bounds.left;
}