C_OUTLINE_LIST *OL_BUCKETS::operator()( // array access
    TDimension x,                       // image coords
    TDimension y) {
  return &buckets[(y - bl.y()) / BUCKETSIZE * bxdim +
                  (x - bl.x()) / BUCKETSIZE];
}