void DEMData::backfillBorder(const DEMData& borderTileData, int8_t dx, int8_t dy) {
    auto& o = borderTileData;

    // Tiles from the same source should always be of the same dimensions.
    assert(dim == o.dim);

    // We determine the pixel range to backfill based which corner/edge `borderTileData`
    // represents. For example, dx = -1, dy = -1 represents the upper left corner of the
    // base tile, so we only need to backfill one pixel at coordinates (-1, -1) of the tile
    // image.
    int32_t xMin = dx * dim;
    int32_t xMax = dx * dim + dim;
    int32_t yMin = dy * dim;
    int32_t yMax = dy * dim + dim;
    
    if (dx == -1) xMin = xMax - 1;
    else if (dx == 1) xMax = xMin + 1;
    
    if (dy == -1) yMin = yMax - 1;
    else if (dy == 1) yMax = yMin + 1;
    
    int32_t ox = -dx * dim;
    int32_t oy = -dy * dim;
    
    auto* dest = reinterpret_cast<uint32_t*>(image.data.get());
    auto* source = reinterpret_cast<uint32_t*>(o.image.data.get());

    for (int32_t y = yMin; y < yMax; y++) {
        for (int32_t x = xMin; x < xMax; x++) {
            dest[idx(x, y)] = source[idx(x + ox, y + oy)];
        }
    }
}