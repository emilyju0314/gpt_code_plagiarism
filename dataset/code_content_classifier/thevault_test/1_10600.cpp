static void MarkAndDeleteImageParts(const FCOORD &rerotate, ColPartitionGrid *part_grid,
                                    ColPartition_LIST *image_parts, Image image_pix) {
  if (image_pix == nullptr) {
    return;
  }
  int imageheight = pixGetHeight(image_pix);
  ColPartition_IT part_it(image_parts);
  for (; !part_it.empty(); part_it.forward()) {
    ColPartition *part = part_it.extract();
    TBOX part_box = part->bounding_box();
    BlobRegionType type = part->blob_type();
    if (!ScanForOverlappingText(part_grid, &part_box) || type == BRT_RECTIMAGE ||
        type == BRT_POLYIMAGE) {
      // Mark the box on the image.
      // All coords need to be rotated to match the image.
      part_box.rotate(rerotate);
      int left = part_box.left();
      int top = part_box.top();
      pixRasterop(image_pix, left, imageheight - top, part_box.width(), part_box.height(), PIX_SET,
                  nullptr, 0, 0);
    }
    DeletePartition(part);
  }
}