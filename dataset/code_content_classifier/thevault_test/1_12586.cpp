void
GenericVcAllocator::release_output_vc(unsigned port, unsigned ovc)
{
    ovc_taken[port][ovc] = false;
}