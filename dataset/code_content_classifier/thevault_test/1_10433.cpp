void C_BLOB::ConstructBlobsFromOutlines(bool good_blob, C_OUTLINE_LIST *outline_list,
                                        C_BLOB_IT *good_blobs_it, C_BLOB_IT *bad_blobs_it) {
  // List of top-level outlines with correctly nested children.
  C_OUTLINE_LIST nested_outlines;
  for (C_OUTLINE_IT ol_it(outline_list); !ol_it.empty(); ol_it.forward()) {
    C_OUTLINE *outline = ol_it.extract();
    // Position this outline in appropriate position in the hierarchy.
    position_outline(outline, &nested_outlines);
  }
  // Check for legal nesting and reassign as required.
  for (C_OUTLINE_IT ol_it(&nested_outlines); !ol_it.empty(); ol_it.forward()) {
    C_OUTLINE *outline = ol_it.extract();
    bool blob_is_good = good_blob;
    if (!outline->IsLegallyNested()) {
      // The blob is illegally nested.
      // Mark it bad, and add all its children to the top-level list.
      blob_is_good = false;
      ol_it.add_list_after(outline->child());
    }
    auto *blob = new C_BLOB(outline);
    // Set inverse flag and reverse if needed.
    blob->CheckInverseFlagAndDirection();
    // Put on appropriate list.
    if (!blob_is_good && bad_blobs_it != nullptr) {
      bad_blobs_it->add_after_then_move(blob);
    } else {
      good_blobs_it->add_after_then_move(blob);
    }
  }
}