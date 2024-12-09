void 
SimpleRouter::do_switch_allocation()
{
    sa_cycles++;    // stat

    for(unsigned p=0; p<ports; p++) { //for each output port
        const SA_unit* sap = swa->pick_winner(p);
	if(sap == 0) //no winner for this port; must be no requestors
	    continue;

        SA_unit sa_winner = *sap;

	unsigned winner_ivc = sa_winner.port*vcs + sa_winner.ch;

	assert(input_buffer_state[winner_ivc].pipe_stage == SWA_REQUESTED);

	if(input_buffer_state[winner_ivc].sa_head_done == false)
	    input_buffer_state[winner_ivc].sa_head_done = true;

	input_buffer_state[winner_ivc].pipe_stage = SW_TRAVERSAL;
#ifdef IRIS_DBG
std::cout << "Router " << node_id << " switch alloc for port " << p << " winner: " << sa_winner.port <<"-"<<sa_winner.ch << " SWA_REQUESTED->SW_TRAVERSAL" << std::endl;
#endif
	//We don't turn off request for switch allocation here. After switch traversal, if we can send
	//more flit, we will go back to VCA_COMPLETE, and at the point the request for SWA will be turned off.
    }

}