void SimpleRouter::do_vc_allocation()
{
    vca_cycles++;

    std::vector<VCA_unit>& vca_current_winners = vca->pick_winner();

    for ( unsigned i=0; i<vca_current_winners.size(); i++) {
	VCA_unit winner = vca_current_winners[i];

	uint ivc = winner.in_port*vcs + winner.in_vc;

	assert( input_buffer_state[ivc].pipe_stage == VCA_REQUESTED );

	input_buffer_state[ivc].output_port = winner.out_port;
	input_buffer_state[ivc].output_channel= winner.out_vc;
	input_buffer_state[ivc].pipe_stage = VCA_COMPLETE; //in the following we check if VCs in VCA_COMPLETE
	                                                   //can move on to SWA_REQUESTED

#ifdef IRIS_DBG
std::cout << "Router " << node_id << " vc " << winner.in_port << "-"<<winner.in_vc <<"-" <<winner.out_port <<"-"<<winner.out_vc << " VCA_REQUESTED->VCA_COMPLETE.\n";
#endif
	// if requesting multiple outports make sure to cancel them as
	// pkt will no longer be VCA_REQUESTED
    }



    //check all input VCs and change their state if applicable.
    for( uint i=0; i<(ports*vcs); i++) {
	//a VC can go from  SW_TRAVERSAL to VCA_COMPLETE; this is
	//a stalled state in which a VC has allocated an output VC but could not go to
	//SWA_REQUESTED becaues input is empty or no credits to send. Check and see if
	//the situation has changed.
        if( input_buffer_state[i].pipe_stage == VCA_COMPLETE) {
            uint ip = input_buffer_state[i].input_port;
            uint ic = input_buffer_state[i].input_channel;
            uint op = input_buffer_state[i].output_port;
            uint oc = input_buffer_state[i].output_channel;

	    //For a VC to go from VCA_COMPLETE to SWA_REQUESTED, there must be input flits and credits.
	    //If the head flit hasn't passed yet, we wait until we have full credits; otherwise, we
	    //require credits > 0.
            if(in_buffers[ip]->get_occupancy(ic)) { //input buffer has flit(s)
	        if( (input_buffer_state[i].sa_head_done && downstream_credits[op][oc] > 0) ||
		   (!input_buffer_state[i].sa_head_done && downstream_credits[op][oc] == CREDITS)) { //has credits
		   //If head flit hasn't been through SWA_REQUESTED yet, we require the output VC has max
		   //credits, meaning, the previous packet using the same output channel has completely left
		   //the downstream router. See pp. 314 of Dally and Towels.
		    //assert(swa->is_requested(op, ip, ic) == false);
		    swa->request(op, oc, ip, ic);
		    input_buffer_state[i].pipe_stage = SWA_REQUESTED;
#ifdef IRIS_DBG
std::cout << "Router " << node_id << " vc " << ip << "-"<<ic <<"-" <<op <<"-"<<oc << " VCA_COMPLETE->SWA_REQUESTED.\n";
#endif
		}
            }
        }
	#if 0
	//moved to do_route_computing()
	else if( input_buffer_state[i].pipe_stage == FULL ) { //new head flit
	    // Check new head flits; enter them into VCA_REQUESTED stage.
            uint ip = input_buffer_state[i].input_port;
            uint ic = input_buffer_state[i].input_channel;
            uint op = input_buffer_state[i].possible_oports[0]; //routing algorithm already determined output port
            uint oc = input_buffer_state[i].possible_ovcs[0];
	    input_buffer_state[i].pipe_stage = VCA_REQUESTED;
	    vca->request(op,oc,ip,ic);
#ifdef IRIS_DBG
std::cout << "Router " << node_id << " vc " << ip << "-"<<ic <<"-" <<op <<"-"<<oc << " FULL->VCA_REQUESTED.\n";
#endif
        }
	#endif
    }
}