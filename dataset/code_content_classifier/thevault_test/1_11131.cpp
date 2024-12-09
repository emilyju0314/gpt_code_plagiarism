C_OUTLINE::C_OUTLINE(CRACKEDGE *startpt, ICOORD bot_left, ICOORD top_right, int16_t length)
    : box(bot_left, top_right), start(startpt->pos), offsets(nullptr) {
  int16_t stepindex; // index to step
  CRACKEDGE *edgept; // current point

  stepcount = length; // no of steps
  if (length == 0) {
    return;
  }
  // get memory
  steps.resize(step_mem());
  edgept = startpt;

  for (stepindex = 0; stepindex < length; stepindex++) {
    // set compact step
    set_step(stepindex, edgept->stepdir);
    edgept = edgept->next;
  }
}