void Wordrec::add_seam_to_queue(float new_priority, SEAM *new_seam, SeamQueue *seams) {
  if (new_seam == nullptr) {
    return;
  }
  if (chop_debug) {
    tprintf("Pushing new seam with priority %g :", new_priority);
    new_seam->Print("seam: ");
  }
  if (seams->size() >= MAX_NUM_SEAMS) {
    SeamPair old_pair(0, nullptr);
    if (seams->PopWorst(&old_pair) && old_pair.key() <= new_priority) {
      if (chop_debug) {
        tprintf("Old seam staying with priority %g\n", old_pair.key());
      }
      delete new_seam;
      seams->Push(&old_pair);
      return;
    } else if (chop_debug) {
      tprintf("New seam with priority %g beats old worst seam with %g\n", new_priority,
              old_pair.key());
    }
  }
  SeamPair new_pair(new_priority, new_seam);
  seams->Push(&new_pair);
}