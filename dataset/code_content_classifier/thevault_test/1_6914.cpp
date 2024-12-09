void JoBS::dropFront(int prio, int strategy) {
	Packet *p;
	hdr_cmn *cm_h;
	
	p = cls_[prio] -> head();
	cm_h = hdr_cmn::access(p);
	total_backlog_Pkts_ --;
	total_backlog_Bits_ -= 8*cm_h->size();
	backlog_Pkts_[prio] --;
	backlog_Bits_[prio] -= 8*cm_h->size();
	Rin_[prio] -= 8*cm_h->size();
	if (strategy == WITH_UPDATE) {
		for (int i = 1; i <= NO_CLASSES; i++) 
			current_loss_[i] = min_drop_[i];
		current_loss_[prio] += (double)8*cm_h -> size()	
		  /(double)Arrival_[prio];
	}
	cls_[prio] -> remove(p);
	drop(p);
	return;
}