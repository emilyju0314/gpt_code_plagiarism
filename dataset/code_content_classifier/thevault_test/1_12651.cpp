void
SimpleArbiter :: clear_request ( unsigned ch )
{
    assert(ch < no_channels);
    requested[ch] = false;
}