void Wordrec::combine_seam(const SeamPile &seam_pile, const SEAM *seam, SeamQueue *seam_queue) {
  for (int x = 0; x < seam_pile.size(); ++x) {
    const SEAM *this_one = seam_pile.get(x).data();
    if (seam->CombineableWith(*this_one, SPLIT_CLOSENESS, chop_ok_split)) {
      SEAM *new_one = new SEAM(*seam);
      new_one->CombineWith(*this_one);
      if (chop_debug > 1) {
        new_one->Print("Combo priority       ");
      }
      add_seam_to_queue(new_one->priority(), new_one, seam_queue);
    }
  }
}