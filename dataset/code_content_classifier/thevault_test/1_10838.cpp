Image IntGrid::ThresholdToPix(int threshold) const {
  Image pix = pixCreate(tright().x() - bleft().x(), tright().y() - bleft().y(), 1);
  int cellsize = gridsize();
  for (int y = 0; y < gridheight(); ++y) {
    for (int x = 0; x < gridwidth(); ++x) {
      if (GridCellValue(x, y) > threshold && GridCellValue(x - 1, y) > 0 &&
          GridCellValue(x + 1, y) > 0 && GridCellValue(x, y - 1) > 0 &&
          GridCellValue(x, y + 1) > 0) {
        pixRasterop(pix, x * cellsize, tright().y() - ((y + 1) * cellsize), cellsize, cellsize,
                    PIX_SET, nullptr, 0, 0);
      }
    }
  }
  return pix;
}