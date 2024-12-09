static void CutChunkFromParts(const TBOX &box, const TBOX &im_box, const FCOORD &rotation,
                              const FCOORD &rerotation, Image pix, ColPartition_LIST *part_list) {
  ASSERT_HOST(!part_list->empty());
  ColPartition_IT part_it(part_list);
  do {
    ColPartition *part = part_it.data();
    TBOX part_box = part->bounding_box();
    if (part_box.overlap(box)) {
      // This part must be cut and replaced with the remains. There are
      // up to 4 pieces to be made. Start with the first one and use
      // add_before_stay_put. For each piece if it has no black pixels
      // left, just don't make the box.
      // Above box.
      if (box.top() < part_box.top()) {
        TBOX slice(part_box);
        slice.set_bottom(box.top());
        if (ImageFind::CountPixelsInRotatedBox(slice, im_box, rerotation, pix) > 0) {
          AttemptToShrinkBox(rotation, rerotation, im_box, pix, &slice);
          part_it.add_before_stay_put(
              ColPartition::FakePartition(slice, PT_UNKNOWN, BRT_POLYIMAGE, BTFT_NONTEXT));
        }
      }
      // Left of box.
      if (box.left() > part_box.left()) {
        TBOX slice(part_box);
        slice.set_right(box.left());
        if (box.top() < part_box.top()) {
          slice.set_top(box.top());
        }
        if (box.bottom() > part_box.bottom()) {
          slice.set_bottom(box.bottom());
        }
        if (ImageFind::CountPixelsInRotatedBox(slice, im_box, rerotation, pix) > 0) {
          AttemptToShrinkBox(rotation, rerotation, im_box, pix, &slice);
          part_it.add_before_stay_put(
              ColPartition::FakePartition(slice, PT_UNKNOWN, BRT_POLYIMAGE, BTFT_NONTEXT));
        }
      }
      // Right of box.
      if (box.right() < part_box.right()) {
        TBOX slice(part_box);
        slice.set_left(box.right());
        if (box.top() < part_box.top()) {
          slice.set_top(box.top());
        }
        if (box.bottom() > part_box.bottom()) {
          slice.set_bottom(box.bottom());
        }
        if (ImageFind::CountPixelsInRotatedBox(slice, im_box, rerotation, pix) > 0) {
          AttemptToShrinkBox(rotation, rerotation, im_box, pix, &slice);
          part_it.add_before_stay_put(
              ColPartition::FakePartition(slice, PT_UNKNOWN, BRT_POLYIMAGE, BTFT_NONTEXT));
        }
      }
      // Below box.
      if (box.bottom() > part_box.bottom()) {
        TBOX slice(part_box);
        slice.set_top(box.bottom());
        if (ImageFind::CountPixelsInRotatedBox(slice, im_box, rerotation, pix) > 0) {
          AttemptToShrinkBox(rotation, rerotation, im_box, pix, &slice);
          part_it.add_before_stay_put(
              ColPartition::FakePartition(slice, PT_UNKNOWN, BRT_POLYIMAGE, BTFT_NONTEXT));
        }
      }
      part->DeleteBoxes();
      delete part_it.extract();
    }
    part_it.forward();
  } while (!part_it.at_first());
}