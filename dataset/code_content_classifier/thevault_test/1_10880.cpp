TBLOB *TBLOB::ShallowCopy(const TBLOB &src) {
  auto *blob = new TBLOB;
  blob->denorm_ = src.denorm_;
  return blob;
}