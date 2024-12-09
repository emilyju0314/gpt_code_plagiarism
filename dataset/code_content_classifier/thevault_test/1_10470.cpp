void outlines_to_blobs( // find blobs
    BLOCK *block,       // block to scan
    ICOORD bleft, ICOORD tright, C_OUTLINE_LIST *outlines) {
  // make buckets
  OL_BUCKETS buckets(bleft, tright);

  fill_buckets(outlines, &buckets);
  empty_buckets(block, &buckets);
}