void IntGrid::Init(int gridsize, const ICOORD &bleft, const ICOORD &tright) {
  GridBase::Init(gridsize, bleft, tright);
  delete[] grid_;
  grid_ = new int[gridbuckets_];
  Clear();
}