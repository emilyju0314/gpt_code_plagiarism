WERD *WERD::ConstructFromSingleBlob(bool bol, bool eol, C_BLOB *blob) {
  C_BLOB_LIST temp_blobs;
  C_BLOB_IT temp_it(&temp_blobs);
  temp_it.add_after_then_move(blob);
  WERD *blob_word = new WERD(&temp_blobs, this);
  blob_word->set_flag(W_BOL, bol);
  blob_word->set_flag(W_EOL, eol);
  return blob_word;
}