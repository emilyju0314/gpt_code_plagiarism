int JoBS::minRatesNeeded(int /*priority*/) {
	int result;
	int i;
	double cur_time;
	Packet* p;
	hdr_cmn* cm_h; 

	cur_time = Scheduler::instance().clock();
	result = TRUE;
  
	for (i = 1; i <= NO_CLASSES; i++) {
		if (cls_[i]->head() != 0 && (concerned_ADC_[i] || concerned_ARC_[i])) {
			p = cls_[i]->head();
			cm_h = hdr_cmn::access(p);

			if (concerned_ADC_[i]) { 
				if ((ADC_[i] - (cur_time-cm_h->ts_)) > 0 ) {
					// min rate needed for ADC
					min_rate_[i] = (double)(backlog_Bits_[i])
					    /(double)(ADC_[i] - (cur_time-cm_h->ts_));
					if (concerned_ARC_[i] && ARC_[i] > min_rate_[i]) {
						// min rate needed for ADC+ARC
						min_rate_[i] = ARC_[i];
					}
				} else 
					min_rate_[i] = INFINITY; 	
			} else if (concerned_ARC_[i]) {
				// no ADC, an ARC
				min_rate_[i] = ARC_[i];
			}
			if (min_rate_[i] > service_rate_[i]) 
				result = FALSE;
		} else 
			min_rate_[i] = 0.0;
	}
	return result;
}