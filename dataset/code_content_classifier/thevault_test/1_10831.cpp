void GridBase::Init(int gridsize, const ICOORD &bleft, const ICOORD &tright) {
  gridsize_ = gridsize;
  bleft_ = bleft;
  tright_ = tright;
  if (gridsize_ == 0) {
    gridsize_ = 1;
  }
  gridwidth_ = (tright.x() - bleft.x() + gridsize_ - 1) / gridsize_;
  gridheight_ = (tright.y() - bleft.y() + gridsize_ - 1) / gridsize_;
  gridbuckets_ = gridwidth_ * gridheight_;
}