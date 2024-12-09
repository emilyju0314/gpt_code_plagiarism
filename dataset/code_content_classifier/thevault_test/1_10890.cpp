void TBLOB::EliminateDuplicateOutlines() {
  for (TESSLINE *outline = outlines; outline != nullptr; outline = outline->next) {
    TESSLINE *last_outline = outline;
    for (TESSLINE *other_outline = outline->next; other_outline != nullptr;
         last_outline = other_outline, other_outline = other_outline->next) {
      if (outline->SameBox(*other_outline)) {
        last_outline->next = other_outline->next;
        // This doesn't leak - the outlines share the EDGEPTs.
        other_outline->loop = nullptr;
        delete other_outline;
        other_outline = last_outline;
        // If it is part of a cut, then it can't be a hole any more.
        outline->is_hole = false;
      }
    }
  }
}