C_BLOB::C_BLOB(C_OUTLINE_LIST *outline_list) {
  for (C_OUTLINE_IT ol_it(outline_list); !ol_it.empty(); ol_it.forward()) {
    C_OUTLINE *outline = ol_it.extract();
    // Position this outline in appropriate position in the hierarchy.
    position_outline(outline, &outlines);
  }
  CheckInverseFlagAndDirection();
}