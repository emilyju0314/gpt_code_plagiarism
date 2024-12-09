void RedPDQueue::enque(Packet* pkt) {
	
	double P_monFlow=0;

	//	hdr_ip* iph = (hdr_ip*)pkt->access(off_ip_);    
	//	int fid = iph->flowid();
	//	int src_ = iph->saddr();
	
	if (flowMonitor_ == NULL) {
		printf("RedPD: ERROR: FlowMonitor Not Found --\n");
		abort();
	}	
	
	RedPDFlow * flow = (RedPDFlow *) flowMonitor_->find(pkt);
	
	if (flow == NULL) {
		printf("RedPD: ERROR: Flow Not Found\n");
		abort();
	}
	
// 	if (debug_) {
// 		printf("flow - %s %d", flow->name(), flow->monitored_);
// 		if (flow->monitored()) 
// 			printf("RedPD: Got a monitored flow :)\n");
// 		else
// 			printf("RedPD: Unmonitored flow :(\n");
// 	}

	if (flow->monitored()) {

		//update the current estimate 
		//if automatic arrival rate estimation is taking place.
		if (flow->auto_) {
			flow->currentBW_ = flow->estRate_;
		}
		
		//calculate drop probability - use the global target if global_target_ is set
		if (global_target_) { 
			P_monFlow = getP_monFlow(flow->currentBW_, targetBW_);
		} 
		else { 
			P_monFlow = getP_monFlow(flow->currentBW_, flow->targetBW_);
		}
		
		if (flow->unresponsive_) {
			//printf("unresponsive penalty = %g\n", unresponsive_penalty_);
			P_monFlow *= unresponsive_penalty_;
		}
		
		if (P_monFlow != 0) {
			flow->lastDropTime_ = Scheduler::instance().clock();
			double mod_p = modify_p(P_monFlow, flow->count, 0, 0, 0, 0, 0);

			P_monFlow = mod_p;
			double u = Random::uniform();
			
			int drop=0;
			
			//don't apply link utilization optimization in testFRp mode
			if (P_testFRp_ != -1 && u <= P_monFlow) {
			    drop =1;
			}

			// drop a packet 
			// 1. flow is responsive & (ave_q > min_th) & queue is not empty
			// 2  flow is unresponsive & (noidle is not set or queue is not empty) 
			int qlen = qib_ ? q_->byteLength() : q_->length();
			if ( P_testFRp_ == -1 && u<= P_monFlow &&
			     (
			      (!flow->unresponsive_ && edv_.v_ave >= edp_.th_min && qlen > 1) ||
			      (flow->unresponsive_ && ( qlen > 1 || !noidle_))
			      )
			     ) {
			    drop = 1;
			}

			if (drop) {
			    //first trace the monitored early drop
			    if (MEDTrace!= NULL) 
				((Trace *)MEDTrace)->recvOnly(pkt);
			    
			    flowMonitor_->mon_edrop(pkt);
			    
			    //there is a bug here, this packet drop does not go to
			    // any other flow monitor attached to the link. 
			    //departures and arrivals still go there if you wanna calculate.
			    Packet::free(pkt);
			    
			    flow->count = 0;
			    return;
			}
			else {
			    flow->count++;
			}
		}
	}
	
	//if not dropped or a non-monitored packet - send it to the RED queue 
	// - but before see if testFRp mode is on
	if (P_testFRp_ != -1) {
	    double p = P_testFRp_;
	    int size = 	(hdr_cmn::access(pkt))->size();
	    if (edp_.bytes) {
		p = (p * size) / edp_.mean_pktsize;
	    }
	    if (debug_) 
		printf("FRp_ mode ON with %g\n",P_testFRp_); 
	    double u = Random::uniform();
	    if (u <= p) {
		drop(pkt);
		return;
	    }
	}
	
	REDQueue::enque(pkt);
}