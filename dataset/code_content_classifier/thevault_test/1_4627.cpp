static int convert2pix(l_uint32 *data, int w, int h, int raster)
{
    int x;
    int w4 = ((w+3)>>2)-1;
    int extra = raster - w >= 4;
    l_uint32 mask = ~(0xFFFFFFFF<<((w&3)*8));

    for (; h > 0; h--) {
        l_uint32 v;
        for (x = w4; x > 0; x--) {
            v = *data;
            *data++ = (v>>24) | ((v & 0xff0000)>>8) | ((v & 0xff00)<<8) | (v<<24);
        }
        v = *data;
        *data++ = (v>>24) | ((v & 0xff0000)>>8) | ((v & 0xff00)<<8) | (v<<24) | mask;
        if (extra)
            *data++ = 0xFFFFFFFF;
    }

    return w + extra*4;
}