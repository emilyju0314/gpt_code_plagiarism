static void prep_y(work &info, iline *table, coord_conv_f coord_f) {
    const int size = static_cast<int>(info.c->raster.pagesize.y);
    const double out_r = (info.out_bbox.ymax - info.out_bbox.ymin) / size;
    const double in_r = info.c->inraster.rsets[info.tl.l].ry;
    double offset = info.in_bbox.ymax - 0.5 * in_r;
    for (int i = 0; i < size; i++) {
        // Coordinate of output line in input projection
        const double coord = coord_f(info.c->eres, info.out_bbox.ymax - out_r * (i + 0.5));
        // Same in pixels
        const double pos = (offset - coord) / in_r;
        table[i].line = static_cast<int>(ceil(pos)); // higher line
        table[i].w = (ceil(pos) == floor(pos)) ? 255 :
            static_cast<int>(floor(256.0 * (pos - floor(pos))));
    }
}