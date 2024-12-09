void JoBS::arvAccounting(Packet* thePacket) {
	int i;
	double cur_time;
	hdr_cmn* cm_h;
	hdr_cmn* cm_h1;
	hdr_cmn* cm_h2; 
	hdr_ip*  ip_h; 
	
	cur_time = Scheduler::instance().clock();
	cm_h = hdr_cmn::access(thePacket);
	ip_h = hdr_ip::access(thePacket);
	
	/* Update curves */
	
	Arrival_[ip_h -> prio()]      += 8*cm_h -> size();
	Rin_    [ip_h -> prio()]      += 8*cm_h -> size();
	if (last_rate_update_[ip_h -> prio()] == 0) {
		last_rate_update_[ip_h -> prio()] = cur_time;
	} else {
		Rout_th_ [ip_h -> prio()]      += (cur_time-last_rate_update_[ip_h -> prio()])*service_rate_[ip_h -> prio()];
		last_rate_update_[ip_h -> prio()] = cur_time;
	}
	backlog_Pkts_[ip_h -> prio()] ++;
	backlog_Bits_[ip_h -> prio()] += 8*cm_h -> size();
	total_backlog_Bits_ += 8*cm_h -> size();
	total_backlog_Pkts_ ++;
	
	for (i = 1; i <= NO_CLASSES; i++) {
		if (Arrival_[i] > 0) {
			current_loss_[i] = (double)(Arrival_[i] - Rin_[i])/(double)(Arrival_[i]);
			min_drop_[i] = (double)(max(0.0, (1.0-(double)(Rin_[i])/(double)Arrival_[i])));
			max_drop_[i] = (double)(min(1.0, (1.0-(double)((double)Rout_[i]/(double)Arrival_[i]))));	
		} else {
			current_loss_[i] = 0;
			min_drop_[i] = 0.0;
			max_drop_[i] = 0.0;
		}
		
		if (cls_[i]->head() != NULL) {
			cm_h1 = hdr_cmn::access(cls_[i]->head());
			cm_h2 = hdr_cmn::access(cls_[i]->tail());
			avg_elapsed_[i] = (2*cur_time - cm_h1 -> ts_ - cm_h2 -> ts_)/((backlog_Pkts_[i]>1)? 2.0 :1.0);
		}
	}
	return;
}