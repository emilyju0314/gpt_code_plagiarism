void ImageFind::FindImagePartitions(Image image_pix, const FCOORD &rotation,
                                    const FCOORD &rerotation, TO_BLOCK *block, TabFind *tab_grid,
                                    DebugPixa *pixa_debug, ColPartitionGrid *part_grid,
                                    ColPartition_LIST *big_parts) {
  int imageheight = pixGetHeight(image_pix);
  Boxa *boxa;
  Pixa *pixa;
  ConnCompAndRectangularize(image_pix, pixa_debug, &boxa, &pixa);
  // Iterate the connected components in the image regions mask.
  int nboxes = 0;
  if (boxa != nullptr && pixa != nullptr) {
    nboxes = boxaGetCount(boxa);
  }
  for (int i = 0; i < nboxes; ++i) {
    l_int32 x, y, width, height;
    boxaGetBoxGeometry(boxa, i, &x, &y, &width, &height);
    Image pix = pixaGetPix(pixa, i, L_CLONE);
    TBOX im_box(x, imageheight - y - height, x + width, imageheight - y);
    im_box.rotate(rotation); // Now matches all partitions and blobs.
    ColPartitionGridSearch rectsearch(part_grid);
    rectsearch.SetUniqueMode(true);
    ColPartition_LIST part_list;
    DivideImageIntoParts(im_box, rotation, rerotation, pix, &rectsearch, &part_list);
    if (textord_tabfind_show_images && pixa_debug != nullptr) {
      pixa_debug->AddPix(pix, "ImageComponent");
      tprintf("Component has %d parts\n", part_list.length());
    }
    pix.destroy();
    if (!part_list.empty()) {
      ColPartition_IT part_it(&part_list);
      if (part_list.singleton()) {
        // We didn't have to chop it into a polygon to fit around text, so
        // try expanding it to merge fragmented image parts, as long as it
        // doesn't touch strong text.
        ColPartition *part = part_it.extract();
        TBOX text_box(im_box);
        MaximalImageBoundingBox(part_grid, &text_box);
        while (ExpandImageIntoParts(text_box, &rectsearch, part_grid, &part)) {
          ;
        }
        part_it.set_to_list(&part_list);
        part_it.add_after_then_move(part);
        im_box = part->bounding_box();
      }
      EliminateWeakParts(im_box, part_grid, big_parts, &part_list);
      // Iterate the part_list and put the parts into the grid.
      for (part_it.move_to_first(); !part_it.empty(); part_it.forward()) {
        ColPartition *image_part = part_it.extract();
        im_box = image_part->bounding_box();
        part_grid->InsertBBox(true, true, image_part);
        if (!part_it.at_last()) {
          ColPartition *neighbour = part_it.data_relative(1);
          image_part->AddPartner(false, neighbour);
          neighbour->AddPartner(true, image_part);
        }
      }
    }
  }
  boxaDestroy(&boxa);
  pixaDestroy(&pixa);
  DeleteSmallImages(part_grid);
#ifndef GRAPHICS_DISABLED
  if (textord_tabfind_show_images) {
    ScrollView *images_win_ = part_grid->MakeWindow(1000, 400, "With Images");
    part_grid->DisplayBoxes(images_win_);
  }
#endif
}