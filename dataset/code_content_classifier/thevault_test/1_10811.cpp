WERD::WERD(C_BLOB_LIST *blob_list, uint8_t blank_count, const char *text)
    : blanks(blank_count), flags(0), script_id_(0), correct(text ? text : "") {
  C_BLOB_IT start_it = &cblobs;
  C_BLOB_IT rej_cblob_it = &rej_cblobs;
  C_OUTLINE_IT c_outline_it;
  int16_t inverted_vote = 0;
  int16_t non_inverted_vote = 0;

  // Move blob_list's elements into cblobs.
  start_it.add_list_after(blob_list);

  /*
  Set white on black flag for the WERD, moving any duff blobs onto the
  rej_cblobs list.
  First, walk the cblobs checking the inverse flag for each outline of each
  cblob. If a cblob has inconsistent flag settings for its different
  outlines, move the blob to the reject list. Otherwise, increment the
  appropriate w-on-b or b-on-w vote for the word.

  Now set the inversion flag for the WERD by maximum vote.

  Walk the blobs again, moving any blob whose inversion flag does not agree
  with the concencus onto the reject list.
*/
  start_it.set_to_list(&cblobs);
  if (start_it.empty()) {
    return;
  }
  for (start_it.mark_cycle_pt(); !start_it.cycled_list(); start_it.forward()) {
    bool reject_blob = false;
    bool blob_inverted;

    c_outline_it.set_to_list(start_it.data()->out_list());
    blob_inverted = c_outline_it.data()->flag(COUT_INVERSE);
    for (c_outline_it.mark_cycle_pt(); !c_outline_it.cycled_list() && !reject_blob;
         c_outline_it.forward()) {
      reject_blob = c_outline_it.data()->flag(COUT_INVERSE) != blob_inverted;
    }
    if (reject_blob) {
      rej_cblob_it.add_after_then_move(start_it.extract());
    } else {
      if (blob_inverted) {
        inverted_vote++;
      } else {
        non_inverted_vote++;
      }
    }
  }

  flags.set(W_INVERSE, (inverted_vote > non_inverted_vote));

  start_it.set_to_list(&cblobs);
  if (start_it.empty()) {
    return;
  }
  for (start_it.mark_cycle_pt(); !start_it.cycled_list(); start_it.forward()) {
    c_outline_it.set_to_list(start_it.data()->out_list());
    if (c_outline_it.data()->flag(COUT_INVERSE) != flags[W_INVERSE]) {
      rej_cblob_it.add_after_then_move(start_it.extract());
    }
  }
}