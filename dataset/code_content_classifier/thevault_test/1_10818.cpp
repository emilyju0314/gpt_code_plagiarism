void WERD::copy_on(WERD *other) {
  bool reversed = other->bounding_box().left() < bounding_box().left();
  C_BLOB_IT c_blob_it(&cblobs);
  C_BLOB_LIST c_blobs;

  c_blobs.deep_copy(&other->cblobs, &C_BLOB::deep_copy);
  if (reversed) {
    c_blob_it.add_list_before(&c_blobs);
  } else {
    c_blob_it.move_to_last();
    c_blob_it.add_list_after(&c_blobs);
  }
  if (!other->rej_cblobs.empty()) {
    C_BLOB_IT rej_c_blob_it(&rej_cblobs);
    C_BLOB_LIST new_rej_c_blobs;

    new_rej_c_blobs.deep_copy(&other->rej_cblobs, &C_BLOB::deep_copy);
    if (reversed) {
      rej_c_blob_it.add_list_before(&new_rej_c_blobs);
    } else {
      rej_c_blob_it.move_to_last();
      rej_c_blob_it.add_list_after(&new_rej_c_blobs);
    }
  }
}