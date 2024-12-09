void TWERD::CopyFrom(const TWERD &src) {
  Clear();
  latin_script = src.latin_script;
  for (auto blob : src.blobs) {
    auto *new_blob = new TBLOB(*blob);
    blobs.push_back(new_blob);
  }
}