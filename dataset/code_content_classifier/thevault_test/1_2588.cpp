static size_t pick_input_level(work &info, double rx, double ry) {
    // The raster levels are in increasing resolution order, test until the best match, both x and y
    size_t choiceX, choiceY;
    size_t over = info.c->oversample;

    const TiledRaster &raster = info.c->inraster;
    for (choiceX = 0; choiceX < (raster.n_levels - 1); choiceX++) {
        double cres = raster.rsets[choiceX].rx;
        cres += cres / raster.pagesize.x / 2; // Add half pixel worth to choose matching level
        if (cres < rx) { // This is the better choice
            if (!over) choiceX -= 1; // Use the lower resolution level if not oversampling
            if (choiceX < raster.skip)
                choiceX = raster.skip; // Only use defined levels
            break;
        }
    }

    for (choiceY = 0; choiceY < (raster.n_levels - 1); choiceY++) {
        double cres = raster.rsets[choiceY].ry;
        cres += cres / raster.pagesize.y / 2; // Add half pixel worth to avoid jitter noise
        if (cres < ry) { // This is the best choice
            if (!over) choiceY -= 1; // Use the higher level if oversampling
            if (choiceY < raster.skip)
                choiceY = raster.skip; // Only use defined levels
            break;
        }
    }

    // Pick the higher level number for normal quality
    info.in_level = (choiceX > choiceY) ? choiceX : choiceY;
    // Make choiceX the lower level, to see how far we would be
    if (choiceY < choiceX) choiceX = choiceY;

    // Use min of higher level or low + max extra
    if (info.in_level > choiceX + info.c->max_extra_levels)
        info.in_level = choiceX + info.c->max_extra_levels;

    return info.in_level;
}