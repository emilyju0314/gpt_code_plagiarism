int Fl::y() {
  BitMap r;
  GetQDGlobalsScreenBits(&r);
  return r.bounds.top + 20; // \todo 20 pixel menu bar?
}