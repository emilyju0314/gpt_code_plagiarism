bool ColPartitionGrid::SmoothRegionType(Image nontext_map, const TBOX &im_box,
                                        const FCOORD &rerotation, bool debug,
                                        ColPartition *part) {
  const TBOX &part_box = part->bounding_box();
  if (debug) {
    tprintf("Smooothing part at:");
    part_box.print();
  }
  BlobRegionType best_type = BRT_UNKNOWN;
  int best_dist = INT32_MAX;
  int max_dist = std::min(part_box.width(), part_box.height());
  max_dist = std::max(max_dist * kMaxNeighbourDistFactor, gridsize() * 2);
  // Search with the pad truncated on each side of the box in turn.
  bool any_image = false;
  bool all_image = true;
  for (int d = 0; d < BND_COUNT; ++d) {
    int dist;
    auto dir = static_cast<BlobNeighbourDir>(d);
    BlobRegionType type = SmoothInOneDirection(dir, nontext_map, im_box,
                                               rerotation, debug, *part, &dist);
    if (debug) {
      tprintf("Result in dir %d = %d at dist %d\n", dir, type, dist);
    }
    if (type != BRT_UNKNOWN && dist < best_dist) {
      best_dist = dist;
      best_type = type;
    }
    if (type == BRT_POLYIMAGE) {
      any_image = true;
    } else {
      all_image = false;
    }
  }
  if (best_dist > max_dist) {
    return false; // Too far away to set the type with it.
  }
  if (part->flow() == BTFT_STRONG_CHAIN && !all_image) {
    return false; // We are not modifying it.
  }
  BlobRegionType new_type = part->blob_type();
  BlobTextFlowType new_flow = part->flow();
  if (best_type == BRT_TEXT && !any_image) {
    new_flow = BTFT_STRONG_CHAIN;
    new_type = BRT_TEXT;
  } else if (best_type == BRT_VERT_TEXT && !any_image) {
    new_flow = BTFT_STRONG_CHAIN;
    new_type = BRT_VERT_TEXT;
  } else if (best_type == BRT_POLYIMAGE) {
    new_flow = BTFT_NONTEXT;
    new_type = BRT_UNKNOWN;
  }
  if (new_type != part->blob_type() || new_flow != part->flow()) {
    part->set_flow(new_flow);
    part->set_blob_type(new_type);
    part->SetBlobTypes();
    if (debug) {
      tprintf("Modified part:");
      part->Print();
    }
    return true;
  } else {
    return false;
  }
}