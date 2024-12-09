int Fl::has_check(Fl_Timeout_Handler cb, void *argp) {
  for (Check** p = &first_check; *p;) {
    Check* t = *p;
    if (t->cb == cb && t->arg == argp) {
      return 1;
    } else {
      p = &(t->next);
    }
  }
  return 0;
}