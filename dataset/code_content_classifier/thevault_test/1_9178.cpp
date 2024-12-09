void
tw_snapshot(tw_lp *lp, size_t state_sz)
{
    assert(lp->pe->delta_buffer[0] && "increase --buddy-size argument!");
    memcpy(lp->pe->delta_buffer[0], &lp->cur_state, state_sz);
}