static Image GridReducedPix(const TBOX &box, int gridsize, ICOORD bleft, int *left, int *bottom) {
  // Compute grid bounds of the outline and pad all round by 1.
  int grid_left = (box.left() - bleft.x()) / gridsize - 1;
  int grid_bottom = (box.bottom() - bleft.y()) / gridsize - 1;
  int grid_right = (box.right() - bleft.x()) / gridsize + 1;
  int grid_top = (box.top() - bleft.y()) / gridsize + 1;
  *left = grid_left;
  *bottom = grid_bottom;
  return pixCreate(grid_right - grid_left + 1, grid_top - grid_bottom + 1, 1);
}