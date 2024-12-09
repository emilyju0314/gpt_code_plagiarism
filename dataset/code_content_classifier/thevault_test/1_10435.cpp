C_BLOB *C_BLOB::FakeBlob(const TBOX &box) {
  C_OUTLINE_LIST outlines;
  C_OUTLINE::FakeOutline(box, &outlines);
  return new C_BLOB(&outlines);
}