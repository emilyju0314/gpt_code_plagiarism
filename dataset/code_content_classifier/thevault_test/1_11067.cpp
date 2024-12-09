void BoxWord::ProcessMatchedBlobs(const TWERD &other,
                                  const std::function<void(int)> &cb) const {
  for (unsigned i = 0; i < length_ && i < other.NumBlobs(); ++i) {
    TBOX blob_box = other.blobs[i]->bounding_box();
    if (blob_box == boxes_[i]) {
      cb(i);
    }
  }
}