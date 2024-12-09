void GridBase::GridCoords(int x, int y, int *grid_x, int *grid_y) const {
  *grid_x = (x - bleft_.x()) / gridsize_;
  *grid_y = (y - bleft_.y()) / gridsize_;
  ClipGridCoords(grid_x, grid_y);
}