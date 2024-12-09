void fl_push_matrix() {
  if (sptr==32)
    Fl::error("fl_push_matrix(): matrix stack overflow.");
  else
    stack[sptr++] = m;
}