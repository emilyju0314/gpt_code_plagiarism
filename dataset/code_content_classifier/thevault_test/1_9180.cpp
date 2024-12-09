void
tw_snapshot_restore(tw_lp *lp, size_t state_sz)
{
    int i;
    tw_clock start = tw_clock_read();
    unsigned char *snapshot = (unsigned char *)lp->pe->cur_event->delta_buddy;
    unsigned char *current_state = (unsigned char *)lp->cur_state.get();

    int ret = LZ4_decompress_fast((char *)snapshot, (char*)lp->pe->delta_buffer[0], state_sz);
    g_tw_pe[0]->stats.s_lz4 += (tw_clock_read() - start);
    if (ret < 0) {
        tw_error(TW_LOC, "LZ4_decompress_fast error");
    }

    snapshot = lp->pe->delta_buffer[0];
    for (i = 0; i < state_sz; i++) {
        current_state[i] = current_state[i] - snapshot[i];
    }
}