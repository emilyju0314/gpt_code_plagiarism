static TBOX MoveAndClipBlob(C_BLOB_IT *src_it, C_BLOB_IT *dest_it,
                            const TBOX &clip_box) {
  C_BLOB *src_blob = src_it->extract();
  TBOX box = src_blob->bounding_box();
  if (!clip_box.contains(box)) {
    int left =
        ClipToRange<int>(box.left(), clip_box.left(), clip_box.right() - 1);
    int right =
        ClipToRange<int>(box.right(), clip_box.left() + 1, clip_box.right());
    int top =
        ClipToRange<int>(box.top(), clip_box.bottom() + 1, clip_box.top());
    int bottom =
        ClipToRange<int>(box.bottom(), clip_box.bottom(), clip_box.top() - 1);
    box = TBOX(left, bottom, right, top);
    delete src_blob;
    src_blob = C_BLOB::FakeBlob(box);
  }
  dest_it->add_after_then_move(src_blob);
  return box;
}