static void ComputeEdgeOffsetsOutlineList(int threshold, Image pix, C_OUTLINE_LIST *list) {
  C_OUTLINE_IT it(list);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    C_OUTLINE *outline = it.data();
    if (pix != nullptr && pixGetDepth(pix) == 8) {
      outline->ComputeEdgeOffsets(threshold, pix);
    } else {
      outline->ComputeBinaryOffsets();
    }
    if (!outline->child()->empty()) {
      ComputeEdgeOffsetsOutlineList(threshold, pix, outline->child());
    }
  }
}