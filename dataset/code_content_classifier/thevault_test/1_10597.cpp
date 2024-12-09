static void DeletePartition(ColPartition *part) {
  BlobRegionType type = part->blob_type();
  if (type == BRT_RECTIMAGE || type == BRT_POLYIMAGE) {
    // The partition owns the boxes of these types, so just delete them.
    part->DeleteBoxes(); // From a previous iteration.
  } else {
    // Once marked, the blobs will be swept up by TidyBlobs.
    part->set_flow(BTFT_NONTEXT);
    part->set_blob_type(BRT_NOISE);
    part->SetBlobTypes();
    part->DisownBoxes(); // Created before FindImagePartitions.
  }
  delete part;
}