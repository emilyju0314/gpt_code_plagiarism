void ColPartitionGrid::FindPartitionMargins(ColPartitionSet *columns,
                                            ColPartition *part) {
  // Set up a rectangle search x-bounded by the column and y by the part.
  TBOX box = part->bounding_box();
  int y = part->MidY();
  // Initial left margin is based on the column, if there is one.
  int left_margin = bleft().x();
  int right_margin = tright().x();
  if (columns != nullptr) {
    ColPartition *column = columns->ColumnContaining(box.left(), y);
    if (column != nullptr) {
      left_margin = column->LeftAtY(y);
    }
    column = columns->ColumnContaining(box.right(), y);
    if (column != nullptr) {
      right_margin = column->RightAtY(y);
    }
  }
  left_margin -= kColumnWidthFactor;
  right_margin += kColumnWidthFactor;
  // Search for ColPartitions that reduce the margin.
  left_margin = FindMargin(box.left() + box.height(), true, left_margin,
                           box.bottom(), box.top(), part);
  part->set_left_margin(left_margin);
  // Search for ColPartitions that reduce the margin.
  right_margin = FindMargin(box.right() - box.height(), false, right_margin,
                            box.bottom(), box.top(), part);
  part->set_right_margin(right_margin);
}