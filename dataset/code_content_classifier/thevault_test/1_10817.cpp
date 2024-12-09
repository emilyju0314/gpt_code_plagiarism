void WERD::join_on(WERD *other) {
  C_BLOB_IT blob_it(&cblobs);
  C_BLOB_IT src_it(&other->cblobs);
  C_BLOB_IT rej_cblob_it(&rej_cblobs);
  C_BLOB_IT src_rej_it(&other->rej_cblobs);

  while (!src_it.empty()) {
    blob_it.add_to_end(src_it.extract());
    src_it.forward();
  }
  while (!src_rej_it.empty()) {
    rej_cblob_it.add_to_end(src_rej_it.extract());
    src_rej_it.forward();
  }
}