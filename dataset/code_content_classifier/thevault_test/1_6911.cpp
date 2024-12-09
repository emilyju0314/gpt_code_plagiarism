double JoBS::projDelay(int i) {
	double cur_time  = Scheduler::instance().clock(); 
	if (cls_[i]->head() != NULL) {
		Packet* p = cls_[i]->head();
		hdr_cmn* cm_h = hdr_cmn::access(p);
		return (cur_time - cm_h -> ts_);
	} else return 0.0; // __NOT REACHED__
}