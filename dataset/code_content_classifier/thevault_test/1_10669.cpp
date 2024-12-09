void Wordrec::add_point_to_list(PointHeap *point_heap, EDGEPT *point) {
  if (point_heap->size() < MAX_NUM_POINTS - 2) {
    PointPair pair(point_priority(point), point);
    point_heap->Push(&pair);
  }

#ifndef GRAPHICS_DISABLED
  if (chop_debug > 2) {
    mark_outline(point);
  }
#endif
}