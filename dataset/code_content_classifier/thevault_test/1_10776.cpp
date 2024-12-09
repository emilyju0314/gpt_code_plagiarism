void TextlineProjection::ConstructProjection(TO_BLOCK *input_block, const FCOORD &rotation,
                                             Image nontext_map) {
  pix_.destroy();
  TBOX image_box(0, 0, pixGetWidth(nontext_map), pixGetHeight(nontext_map));
  x_origin_ = 0;
  y_origin_ = image_box.height();
  int width = (image_box.width() + scale_factor_ - 1) / scale_factor_;
  int height = (image_box.height() + scale_factor_ - 1) / scale_factor_;

  pix_ = pixCreate(width, height, 8);
  ProjectBlobs(&input_block->blobs, rotation, image_box, nontext_map);
  ProjectBlobs(&input_block->large_blobs, rotation, image_box, nontext_map);
  Image final_pix = pixBlockconv(pix_, 1, 1);
  //  Pix* final_pix = pixBlockconv(pix_, 2, 2);
  pix_.destroy();
  pix_ = final_pix;
}