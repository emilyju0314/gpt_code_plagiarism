void Wordrec::choose_best_seam(SeamQueue *seam_queue, const SPLIT *split, PRIORITY priority,
                               SEAM **seam_result, TBLOB *blob, SeamPile *seam_pile) {
  SEAM *seam;
  char str[80];
  float my_priority;
  /* Add seam of split */
  my_priority = priority;
  if (split != nullptr) {
    TPOINT split_point = split->point1->pos;
    split_point += split->point2->pos;
    split_point /= 2;
    seam = new SEAM(my_priority, split_point, *split);
    if (chop_debug > 1) {
      seam->Print("Partial priority    ");
    }
    add_seam_to_queue(my_priority, seam, seam_queue);

    if (my_priority > chop_good_split) {
      return;
    }
  }

  TBOX bbox = blob->bounding_box();
  /* Queue loop */
  while (!seam_queue->empty()) {
    SeamPair seam_pair;
    seam_queue->Pop(&seam_pair);
    seam = seam_pair.extract_data();
    /* Set full priority */
    my_priority =
        seam->FullPriority(bbox.left(), bbox.right(), chop_overlap_knob, chop_centered_maxwidth,
                           chop_center_knob, chop_width_change_knob);
    if (chop_debug) {
      sprintf(str, "Full my_priority %0.0f,  ", my_priority);
      seam->Print(str);
    }

    if ((*seam_result == nullptr || (*seam_result)->priority() > my_priority) &&
        my_priority < chop_ok_split) {
      /* No crossing */
      if (seam->IsHealthy(*blob, chop_min_outline_points, chop_min_outline_area)) {
        delete *seam_result;
        *seam_result = new SEAM(*seam);
        (*seam_result)->set_priority(my_priority);
      } else {
        delete seam;
        seam = nullptr;
        my_priority = BAD_PRIORITY;
      }
    }

    if (my_priority < chop_good_split) {
      delete seam;
      return; /* Made good answer */
    }

    if (seam) {
      /* Combine with others */
      if (seam_pile->size() < chop_seam_pile_size) {
        combine_seam(*seam_pile, seam, seam_queue);
        SeamDecPair pair(seam_pair.key(), seam);
        seam_pile->Push(&pair);
      } else if (chop_new_seam_pile && seam_pile->size() == chop_seam_pile_size &&
                 seam_pile->PeekTop().key() > seam_pair.key()) {
        combine_seam(*seam_pile, seam, seam_queue);
        SeamDecPair pair;
        seam_pile->Pop(&pair); // pop the worst.
        // Replace the seam in pair (deleting the old one) with
        // the new seam and score, then push back into the heap.
        pair.set_key(seam_pair.key());
        pair.set_data(seam);
        seam_pile->Push(&pair);
      } else {
        delete seam;
      }
    }

    my_priority = seam_queue->empty() ? NO_FULL_PRIORITY : seam_queue->PeekTop().key();
    if ((my_priority > chop_ok_split) || (my_priority > chop_good_split && split)) {
      return;
    }
  }
}