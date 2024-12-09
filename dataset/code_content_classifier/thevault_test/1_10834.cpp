void IntGrid::Rotate(const FCOORD &rotation) {
  ASSERT_HOST(rotation.x() == 0.0f || rotation.y() == 0.0f);
  ICOORD old_bleft(bleft());
  // ICOORD old_tright(tright());
  int old_width = gridwidth();
  int old_height = gridheight();
  TBOX box(bleft(), tright());
  box.rotate(rotation);
  int *old_grid = grid_;
  grid_ = nullptr;
  Init(gridsize(), box.botleft(), box.topright());
  // Iterate over the old grid, copying data to the rotated position in the new.
  int oldi = 0;
  FCOORD x_step(rotation);
  x_step *= gridsize();
  for (int oldy = 0; oldy < old_height; ++oldy) {
    FCOORD line_pos(old_bleft.x(), old_bleft.y() + gridsize() * oldy);
    line_pos.rotate(rotation);
    for (int oldx = 0; oldx < old_width; ++oldx, line_pos += x_step, ++oldi) {
      int grid_x, grid_y;
      GridCoords(static_cast<int>(line_pos.x() + 0.5), static_cast<int>(line_pos.y() + 0.5),
                 &grid_x, &grid_y);
      grid_[grid_y * gridwidth() + grid_x] = old_grid[oldi];
    }
  }
  delete[] old_grid;
}