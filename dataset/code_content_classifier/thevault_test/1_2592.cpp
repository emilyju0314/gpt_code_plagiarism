static void prep_x(work &info, iline *table) {
    bbox_t &bbox = info.out_equiv_bbox;
    const double out_r = (bbox.xmax - bbox.xmin) / info.c->raster.pagesize.x;
    const double in_r = info.c->inraster.rsets[info.tl.l].rx;
    const double offset = bbox.xmin - info.in_bbox.xmin + 0.5 * (out_r - in_r);
    init_ilines(in_r, out_r, offset, table, static_cast<int>(info.c->raster.pagesize.x));
}