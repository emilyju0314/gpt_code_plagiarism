void ColPartitionGrid::ListFindMargins(ColPartitionSet **best_columns,
                                       ColPartition_LIST *parts) {
  ColPartition_IT part_it(parts);
  for (part_it.mark_cycle_pt(); !part_it.cycled_list(); part_it.forward()) {
    ColPartition *part = part_it.data();
    ColPartitionSet *columns = nullptr;
    if (best_columns != nullptr) {
      const TBOX &part_box = part->bounding_box();
      // Get the columns from the y grid coord.
      int grid_x, grid_y;
      GridCoords(part_box.left(), part_box.bottom(), &grid_x, &grid_y);
      columns = best_columns[grid_y];
    }
    FindPartitionMargins(columns, part);
  }
}