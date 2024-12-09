void ColPartitionSet::GetColumnBoxes(int y_bottom, int y_top,
                                     ColSegment_LIST *segments) {
  ColPartition_IT it(&parts_);
  ColSegment_IT col_it(segments);
  col_it.move_to_last();
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *part = it.data();
    ICOORD bot_left(part->LeftAtY(y_top), y_bottom);
    ICOORD top_right(part->RightAtY(y_bottom), y_top);
    auto *col_seg = new ColSegment();
    col_seg->InsertBox(TBOX(bot_left, top_right));
    col_it.add_after_then_move(col_seg);
  }
}