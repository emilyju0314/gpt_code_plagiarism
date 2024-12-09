void 
SimpleRouter::do_switch_traversal()
{
    for( uint i=0; i<ports*vcs; i++) { //for each vc
        if( input_buffer_state[i].pipe_stage == SW_TRAVERSAL) {
            uint op = input_buffer_state[i].output_port;
            uint oc = input_buffer_state[i].output_channel;
            uint ip = input_buffer_state[i].input_port;
            uint ic= input_buffer_state[i].input_channel;

            if( in_buffers[ip]->get_occupancy(ic)> 0 && downstream_credits[op][oc]>0 ) {
                Flit* f = in_buffers[ip]->pull(ic);
                f->virtual_channel = oc;

                if( f->type == TAIL || f->pkt_length == 1) {
                    // Update packet stats
                    uint lat = manifold::kernel::Manifold::NowTicks() - input_buffer_state[i].pkt_arrival_time;
                    avg_router_latency += lat;
                    stat_packets_out++;
                    stat_pp_packets_out[op][oc]++;
                    stat_pp_pkt_out_cy[op][oc] = manifold::kernel::Manifold::NowTicks();
                    stat_pp_avg_lat[op][oc] += lat;

                    input_buffer_state[i].pipe_stage = EMPTY;
                    input_buffer_state[i].input_port = -1;
                    input_buffer_state[i].input_channel = -1;
                    input_buffer_state[i].output_port = -1;
                    input_buffer_state[i].output_channel = -1;
                    input_buffer_state[i].possible_oports.clear();
                    input_buffer_state[i].possible_ovcs.clear();

		    vca->release_output_vc(op, oc); //VC allocator can release the output VC
                    swa->clear_requestor(op, ip, ic); //Switch Allocation no longer needed
#ifdef IRIS_DBG
std::cout << "Router " << node_id << " vc " << ip << "-"<<ic <<"-" <<op <<"-"<<oc << " SWA_TRAVERSAL->EMPTY.\n";
#endif
                }
		else {
		    //See if we can send more flits; if so, go to SWA_REQUESTED; otherwise,
		    //go to VCA_COMPLETE.
		    if( in_buffers[ip]->get_occupancy(ic)> 0 && downstream_credits[op][oc]>1) {
		        //note credits have not been decremented yet; so compare againt 1
			input_buffer_state[i].pipe_stage = SWA_REQUESTED;
#ifdef IRIS_DBG
std::cout << "Router " << node_id << " switch traversal for " << ip << "-" << ic << ", SW_TRAVERSAL->SWA_REQUESTED" << std::endl;
#endif
			swa->request(op, oc, ip, ic);
		    }
		    else {
#ifdef IRIS_DBG
std::cout << "Router " << node_id << " switch traversal for " << ip << "-" << ic << ", SW_TRAVERSAL->VCA_COMPLETE" << std::endl;
#endif
			input_buffer_state[i].pipe_stage = VCA_COMPLETE;
			swa->clear_requestor(op, ip, ic);
		    }

		}

                stat_flits_out++;
                st_cycles++;

                LinkData* ld = new LinkData();
                ld->type = FLIT;
                ld->src = this->node_id;
                f->virtual_channel = oc;
                ld->f = f;
                ld->vc = oc;

#ifdef IRIS_DBG
cout << "@ " << manifold::kernel::Manifold::NowTicks() << " Router " << node_id << " sending flit to port " << op << ": " << f->toString() << endl;
#endif
                Send(op, ld);    //schedule cannot be used here as the component is not on the same LP
                downstream_credits[op][oc]--;

                LinkData* ldc = new LinkData();
                ldc->type = CREDIT;
                ldc->src = this->node_id;
                ldc->vc = ic;

#ifdef IRIS_DBG
cout << "@ " << manifold::kernel::Manifold::NowTicks() << " router " << node_id << "  credit to port " << ip << endl;
#endif
                Send(ip, ldc);
                stat_last_flit_out_cycle= manifold::kernel::Manifold::NowTicks();
            }
            else { //either no input flits or no credits, or both
	    //We may never reach here!
#ifdef IRIS_DBG
std::cout << "Router " << node_id << " switch traversal for " << ip << "-" << ic << ", SW_TRAVERSAL->VCA_COMPLETE due to lack of input or credit" << std::endl;
#endif
                input_buffer_state[i].pipe_stage = VCA_COMPLETE;
                swa->clear_requestor(op, ip, ic);
            }
        }//in SW_TRAVERSAL
    }//for
}