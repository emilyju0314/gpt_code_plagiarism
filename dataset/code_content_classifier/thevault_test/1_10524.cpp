bool Tesseract::word_dumper(PAGE_RES_IT *pr_it) {
  if (pr_it->block()->block != nullptr) {
    tprintf("\nBlock data...\n");
    pr_it->block()->block->print(nullptr, false);
  }
  tprintf("\nRow data...\n");
  pr_it->row()->row->print(nullptr);
  tprintf("\nWord data...\n");
  WERD_RES *word_res = pr_it->word();
  word_res->word->print();
  if (word_res->blamer_bundle != nullptr && wordrec_debug_blamer &&
      word_res->blamer_bundle->incorrect_result_reason() != IRR_CORRECT) {
    tprintf("Current blamer debug: %s\n", word_res->blamer_bundle->debug().c_str());
  }
  return true;
}