void WERD::GetNoiseOutlines(std::vector<C_OUTLINE *> *outlines) {
  C_BLOB_IT rej_it(&rej_cblobs);
  for (rej_it.mark_cycle_pt(); !rej_it.empty(); rej_it.forward()) {
    C_BLOB *blob = rej_it.extract();
    C_OUTLINE_IT ol_it(blob->out_list());
    outlines->push_back(ol_it.extract());
    delete blob;
  }
}