static int Depth(const CordRep* rep) {
  if (rep->tag == CONCAT) {
    return rep->concat()->depth();
  } else {
    return 0;
  }
}