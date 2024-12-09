void ColPartitionSet::DisplayColumnEdges(int y_bottom, int y_top,
                                         ScrollView *win) {
  ColPartition_IT it(&parts_);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *part = it.data();
    win->Line(part->LeftAtY(y_top), y_top, part->LeftAtY(y_bottom), y_bottom);
    win->Line(part->RightAtY(y_top), y_top, part->RightAtY(y_bottom), y_bottom);
  }
}