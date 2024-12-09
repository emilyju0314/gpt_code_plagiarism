TESSLINE *TESSLINE::BuildFromOutlineList(EDGEPT *outline) {
  auto *result = new TESSLINE;
  result->loop = outline;
  if (outline->src_outline != nullptr) {
    // ASSUMPTION: This function is only ever called from ApproximateOutline
    // and therefore either all points have a src_outline or all do not.
    // Just as SetupFromPos sets the vectors from the vertices, setup the
    // step_count members to indicate the (positive) number of original
    // C_OUTLINE steps to the next vertex.
    EDGEPT *pt = outline;
    do {
      pt->step_count = pt->next->start_step - pt->start_step;
      if (pt->step_count < 0) {
        pt->step_count += pt->src_outline->pathlength();
      }
      pt = pt->next;
    } while (pt != outline);
  }
  result->SetupFromPos();
  return result;
}