void copy_into(mve::ByteImage::ConstPtr src, int x, int y,
    mve::ByteImage::Ptr dest, int border = 0) {

    assert(x >= 0 && x + src->width() + 2 * border <= dest->width());
    assert(y >= 0 && y + src->height() + 2 * border <= dest->height());

    for (int i = 0; i < src->width() + 2 * border; ++i) {
        for(int j = 0; j < src->height() + 2 * border; j++) {
            int sx = i - border;
            int sy = j - border;

            if (sx < 0 || sx >= src->width() || sy < 0 || sy >= src->height())
                continue;

            for (int c = 0; c < src->channels(); ++c) {
                dest->at(x + i, y + j, c) = src->at(sx, sy, c);
            }
        }
    }
}