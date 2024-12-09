static int IntersectArea(const TBOX &box, ColPartition_LIST *part_list) {
  int intersect_area = 0;
  ColPartition_IT part_it(part_list);
  // Iterate the parts and subtract intersecting area.
  for (part_it.mark_cycle_pt(); !part_it.cycled_list(); part_it.forward()) {
    ColPartition *image_part = part_it.data();
    TBOX intersect = box.intersection(image_part->bounding_box());
    intersect_area += intersect.area();
  }
  return intersect_area;
}