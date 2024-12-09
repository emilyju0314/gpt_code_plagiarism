static bool capture_children(OL_BUCKETS *buckets,  // bucket sort class
                             C_BLOB_IT *reject_it, // dead grandchildren
                             C_OUTLINE_IT *blob_it // output outlines
) {
  // master outline
  auto outline = blob_it->data();
  // no of children
  int32_t child_count;
  if (edges_use_new_outline_complexity) {
    child_count =
        buckets->outline_complexity(outline, edges_children_count_limit, 0);
  } else {
    child_count = buckets->count_children(outline, edges_children_count_limit);
  }
  if (child_count > edges_children_count_limit) {
    return false;
  }

  if (child_count > 0) {
    buckets->extract_children(outline, blob_it);
  }
  return true;
}