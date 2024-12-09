void
SimpleArbiter::request ( unsigned ch )
{
    assert(ch < no_channels);
    requested[ch] = true;
}