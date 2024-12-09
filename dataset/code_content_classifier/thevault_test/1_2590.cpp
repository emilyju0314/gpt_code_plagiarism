static void bbox_to_tile(const TiledRaster &raster, size_t level, const bbox_t &bb, sz5 &tl_tile, sz5 &br_tile) {
    double rx = raster.rsets[level].rx;
    double ry = raster.rsets[level].ry;
    double x = (bb.xmin - raster.bbox.xmin) / (rx * raster.pagesize.x);
    double y = (raster.bbox.ymax - bb.ymax) / (ry * raster.pagesize.y);

    // Truncate is fine for these two, after adding quarter pixel to eliminate jitter
    // X and Y are in pages, so a pixel is 1/pagesize
    tl_tile.x = int(x + 0.25 / raster.pagesize.x);
    tl_tile.y = int(y + 0.25 / raster.pagesize.y);

    x = (bb.xmax - raster.bbox.xmin) / (rx * raster.pagesize.x);
    y = (raster.bbox.ymax - bb.ymin) / (ry * raster.pagesize.y);

    // Pad these quarter pixel to avoid jitter
    br_tile.x = int(x + 0.25 / raster.pagesize.x);
    br_tile.y = int(y + 0.25 / raster.pagesize.y);
    // Use a tile only if we get more than half pixel in
    if (x - br_tile.x > 0.5 / raster.pagesize.x) br_tile.x++;
    if (y - br_tile.y > 0.5 / raster.pagesize.y) br_tile.y++;
}