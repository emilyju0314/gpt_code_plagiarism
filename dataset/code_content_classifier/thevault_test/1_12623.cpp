void SimpleRouter :: do_output_to_router_prediction()
{
    const int PIPE_DEPTH = 4;

    for (unsigned p = 0; p < ports; p++) { //for all ports
	if (!port_cross_lp[p])
	    continue;
	    
	BorderPort* bp = this->border_ports[p];
 	assert(bp != 0);

	//check each input vc
	bool inited = false;
	Ticks_t pred = 0; //forecast for port p

	for(unsigned q=0; q<ports; q++) {
	    if(q == p) {//when flit from p leaves the router, credit is sent out of p
		for(unsigned v=0; v<vcs; v++) { //for each vc
		    Ticks_t vc_pred = 0;
		    switch(input_buffer_state[q*vcs + v].pipe_stage) {
			case PS_INVALID:
			case EMPTY:
			case FULL:
			    vc_pred = PIPE_DEPTH;
			    break;
			case VCA_REQUESTED:
			    vc_pred = 2;
			    break;
			case VCA_COMPLETE:
			    vc_pred = 2;
			    break;
			case SWA_REQUESTED:
			    vc_pred = 1;
			    break;
			case SW_TRAVERSAL:
			    vc_pred = 0;
			    break;
		    }//switch
		    if(inited == false) {
			pred = vc_pred;
			inited = true;
		    }
		    else {
			if(vc_pred < pred)
			    pred = vc_pred;
		    }
		    if(pred == 0)
		        break; //if credit could be sent right away, this port is done.
		}//for each vc
            }//if q==p
	    else { //q != p
		for(unsigned v=0; v<vcs; v++) { //for each vc
		    Ticks_t vc_pred = 0;
		    int oport = input_buffer_state[q*vcs+v].output_port;
		    switch(input_buffer_state[q*vcs + v].pipe_stage) {
			case PS_INVALID:
			case EMPTY:
			case FULL:
			    vc_pred = PIPE_DEPTH - 1; //why DEPTH-1? Because the current tick has not been processed.
			                              //assume state is EMPTY, and there's a head flit arriving this tick.
						      //When the event is processed, do_input_buffering() puts the state
						      //to FULL, and after tick() at t, it changes to VCA_REQUESTED, after
						      //tick() at t+1 it becomes SWA_REQUESTED, after tick() at t+2 SW_TRAVERSAL,
						      //at t+3 it goes out. So at t we can only predict t+3, which is 3 ticks
						      //from now.
			    break;
			case VCA_REQUESTED:
                            if(input_buffer_state[q*vcs+v].possible_oports[0] == p)
			        vc_pred = 2;
			    else
				vc_pred = PIPE_DEPTH;
			    break;
			case VCA_COMPLETE:
			    if(oport == p)
				vc_pred = 2;
			    else
				vc_pred = PIPE_DEPTH;
			    break;
			case SWA_REQUESTED:
			    if(oport == p)
				vc_pred = 1;
			    else
				vc_pred = PIPE_DEPTH;
			    break;
			case SW_TRAVERSAL:
			    if(oport == p)
				vc_pred = 0;
			    else
				vc_pred = PIPE_DEPTH;
			    break;
		    }//switch

		    if(inited == false) {
			pred = vc_pred;
			inited = true;
		    }
		    else {
			if(vc_pred < pred)
			    pred = vc_pred;
		    }

		    if(pred == 0)
			break; //no need to continue b/c one flit could be sent right away
		}//for each vc
	    }//q != p

	    if(pred == 0)
		break; //no need to continue b/c a flit or credit could be sent right away
	}//for each port q

#if 0
cout << "@ " << Manifold::NowTicks() << " pppppppppp router" << node_id << " port " << p << " pred= " << pred << endl;
#endif
	pred += manifold::kernel::Manifold::NowTicks();
	bp->update_output_tick(pred);
    }//for each port p

}