OL_BUCKETS::OL_BUCKETS(ICOORD bleft, // corners
                       ICOORD tright)
    : bxdim((tright.x() - bleft.x()) / BUCKETSIZE + 1),
      bydim((tright.y() - bleft.y()) / BUCKETSIZE + 1),
      buckets(bxdim * bydim),
      bl(bleft),
      tr(tright) {}