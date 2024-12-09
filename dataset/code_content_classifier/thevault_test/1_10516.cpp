static void show_point(PAGE_RES *page_res, float x, float y) {
  FCOORD pt(x, y);
  PAGE_RES_IT pr_it(page_res);

  const int kBufsize = 512;
  char msg[kBufsize];
  char *msg_ptr = msg;

  msg_ptr += sprintf(msg_ptr, "Pt:(%0.3f, %0.3f) ", x, y);

  for (WERD_RES *word = pr_it.word(); word != nullptr; word = pr_it.forward()) {
    if (pr_it.row() != pr_it.prev_row() && pr_it.row()->row->bounding_box().contains(pt)) {
      msg_ptr += sprintf(msg_ptr, "BL(x)=%0.3f ", pr_it.row()->row->base_line(x));
    }
    if (word->word->bounding_box().contains(pt)) {
      TBOX box = word->word->bounding_box();
      msg_ptr += sprintf(msg_ptr, "Wd(%d, %d)/(%d, %d) ", box.left(), box.bottom(), box.right(),
                         box.top());
      C_BLOB_IT cblob_it(word->word->cblob_list());
      for (cblob_it.mark_cycle_pt(); !cblob_it.cycled_list(); cblob_it.forward()) {
        C_BLOB *cblob = cblob_it.data();
        box = cblob->bounding_box();
        if (box.contains(pt)) {
          msg_ptr += sprintf(msg_ptr, "CBlb(%d, %d)/(%d, %d) ", box.left(), box.bottom(),
                             box.right(), box.top());
        }
      }
    }
  }
  image_win->AddMessage(msg);
}