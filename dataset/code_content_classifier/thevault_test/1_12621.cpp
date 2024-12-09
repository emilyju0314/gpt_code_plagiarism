manifold::kernel::Ticks_t SimpleRouter :: earliest_to_NI()
{
    for(unsigned i=0; i<ports; i++) {
#if 1
        if(i == PORT_NI)
	    continue;
        for(unsigned j=0; j<vcs; j++) {
	    if(input_buffer_state[i*vcs+j].output_port == PORT_NI)
	        return 0;
        }
#endif 
    }

    //There are no flits for the NI.
    return 4; //takes at least 4 cycles for a head flt to arrive at NI
}