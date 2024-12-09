IntGrid *IntGrid::NeighbourhoodSum() const {
  auto *sumgrid = new IntGrid(gridsize(), bleft(), tright());
  for (int y = 0; y < gridheight(); ++y) {
    for (int x = 0; x < gridwidth(); ++x) {
      int cell_count = 0;
      for (int yoffset = -1; yoffset <= 1; ++yoffset) {
        for (int xoffset = -1; xoffset <= 1; ++xoffset) {
          int grid_x = x + xoffset;
          int grid_y = y + yoffset;
          ClipGridCoords(&grid_x, &grid_y);
          cell_count += GridCellValue(grid_x, grid_y);
        }
      }
      if (GridCellValue(x, y) > 1) {
        sumgrid->SetGridCell(x, y, cell_count);
      }
    }
  }
  return sumgrid;
}