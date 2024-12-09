void SimpleRouter :: do_route_computing()
{
    unsigned idx = 0;
    for(unsigned p=0; p<ports; p++) {
	for(unsigned v=0; v<vcs; v++, idx++) {
	    // idx == p*vcs + v

	    // Check new head flits; enter them into VCA_REQUESTED stage.
	    if(input_buffer_state[idx].pipe_stage == FULL) {

		input_buffer_state[idx].possible_oports.clear();
		unsigned rc_port = decoders[p]->get_output_port(v);
		input_buffer_state[idx].possible_oports.push_back(rc_port);

		input_buffer_state[idx].possible_ovcs.clear();
		unsigned rc_vc = decoders[p]->get_virtual_channel(v);
		input_buffer_state[idx].possible_ovcs.push_back(rc_vc);

		assert ( input_buffer_state[idx].possible_oports.size() != 0);
		assert ( input_buffer_state[idx].possible_ovcs.size() != 0);

		assert(p == input_buffer_state[idx].input_port);
		assert(v == input_buffer_state[idx].input_channel);

		unsigned op = input_buffer_state[idx].possible_oports[0];
		unsigned oc = input_buffer_state[idx].possible_ovcs[0];
		input_buffer_state[idx].pipe_stage = VCA_REQUESTED;
		vca->request(op,oc,p,v);
#ifdef IRIS_DBG
std::cout << "Router " << node_id << " vc " << p << "-"<< v <<"-" << op <<"-"<< oc << " FULL->VCA_REQUESTED.\n";
#endif
	    }
	}
    }
}