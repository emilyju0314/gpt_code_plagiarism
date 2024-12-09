void
GenericSwitchArbiter::clear_requestor( uint oport, uint inport, uint ich)
{
    requested[oport][inport*vcs+ich] = false;
}