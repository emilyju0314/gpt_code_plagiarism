static void tw_delta_alloc(tw_pe *pe) {
    g_tw_delta_sz = LZ4_compressBound(g_tw_delta_sz);

    pe->delta_buffer[0] = (unsigned char *)tw_calloc(TW_LOC, "Delta buffers", g_tw_delta_sz, 1);
    pe->delta_buffer[1] = (unsigned char *)tw_calloc(TW_LOC, "Delta buffers", g_tw_delta_sz, 1);
    pe->delta_buffer[2] = (unsigned char *)tw_calloc(TW_LOC, "Delta buffers", g_tw_delta_sz, 1);
}