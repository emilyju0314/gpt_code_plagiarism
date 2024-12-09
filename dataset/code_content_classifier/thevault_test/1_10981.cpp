void WERD_RES::DebugTopChoice(const char *msg) const {
  tprintf("Best choice: accepted=%d, adaptable=%d, done=%d : ", tess_accepted,
          tess_would_adapt, done);
  if (best_choice == nullptr) {
    tprintf("<Null choice>\n");
  } else {
    best_choice->print(msg);
  }
}