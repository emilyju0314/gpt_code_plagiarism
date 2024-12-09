int JoBS::pickDroppedRLC(int mode) {
	double Mean;
	double loss_error[NO_CLASSES+1];
	int i, activeClasses, backloggedClasses;
	int class_dropped;
	double maxError;
	double maxALC;
	double cur_time  = Scheduler::instance().clock(); 

	hdr_cmn* cm_h; 
	
	class_dropped = -1;
	maxError = 0;
	Mean = 0;
	activeClasses = 0;
	backloggedClasses = 0;
	
	for (i = 1; i <= NO_CLASSES; i++) 
		if (cls_[i]->head() != NULL) {
			backloggedClasses ++;
			if (concerned_RLC_[i]) {
				Mean += loss_prod_others_[i]*current_loss_[i];
				activeClasses ++;
			}    
		}
	
	if (activeClasses > 0) 
		Mean /= (double)activeClasses;
	else if (backloggedClasses == 0) {
		fprintf(stderr, "JoBS::pickDroppedRLC() called but there's no backlog!\n");
		abort();
	}

	if (activeClasses == 0) 
		class_dropped = NO_CLASSES+1; // no classes are concerned by RLCs (NO_CLASSES+1 means "ignore RLC")
	else {
		for (i = 1; i <= NO_CLASSES; i++) 
			if ((cls_[i]->head() != NULL)&&(concerned_RLC_[i])) 
				loss_error[i]=loss_prod_others_[i]*current_loss_[i]-Mean;
			else 
				loss_error[i] = INFINITY; 
    
		for (i = 1; i <= NO_CLASSES; i++)
			if ((cls_[i]->head() != NULL)&&(loss_error[i] <= maxError)) {
				maxError = loss_error[i]; // Find out which class is the most below the mean
				class_dropped = i;   // It's the one that needs to be dropped
				// Ties are broken in favor of the higher priority classes (i.e., if
				// two classes present the same deviation, the lower priority class 
				// will get dropped).
			} 
		
		if (class_dropped != -1) {
			if (drop_front_)
				cm_h = hdr_cmn::access(cls_[class_dropped] -> head());
			else
				cm_h = hdr_cmn::access(cls_[class_dropped] -> tail());

			if (current_loss_[class_dropped]+(double)8*cm_h -> size()/(double)Arrival_[class_dropped] > ALC_[class_dropped])
				class_dropped = NO_CLASSES+1; // the class to drop for meeting the RLC will defeat the ALC: ignore RLC.
		} else 
			class_dropped = NO_CLASSES+1;
	}

	if (class_dropped != -1) { // this test is here only for "safety purposes" 
		// it should always return true at this point.
		if (class_dropped == NO_CLASSES+1) {
			maxALC = -INFINITY;
			for (i = 1; i <= NO_CLASSES; i++) {
				if (cls_[i] -> tail() != NULL) {
					if (ALC_[i]-current_loss_[i] > maxALC)
					{
						;
					}
					maxALC = ALC_[i]-current_loss_[i]; // pick the class which is the furthest from its ALC
					class_dropped = i;
				}
			}
			if (drop_front_)
			  cm_h = hdr_cmn::access(cls_[class_dropped]->head());
			else
			  cm_h = hdr_cmn::access(cls_[class_dropped]->tail());
			if ((mode == RESOLVE_OVERFLOW)
			    &&(current_loss_[class_dropped]+(double)8*cm_h -> size()/(double)Arrival_[class_dropped] > ALC_[class_dropped])) {

				fprintf(stderr, "*** Warning at time t=%f: ALC violated in class %d on link %d\n(reason: buffer overflow impossible to resolve otherwise)\nPkt size=%d bits\told_loss[%d]=%f\tnew_loss[%d]=%f\tArrival_[%d]=%f\tALC[%d]=%f\n",
					cur_time, link_id_,
					class_dropped, 8*cm_h -> size(),
					class_dropped, current_loss_[class_dropped],
					class_dropped, current_loss_[class_dropped]+(double)8*cm_h -> size()/(double)Arrival_[class_dropped],
					class_dropped, (double)Arrival_[class_dropped],
					class_dropped, ALC_[class_dropped]);
			}
		}		
	} else {
		fprintf(stderr, "Trying to drop a packet, but there's nothing in any queue!\n");
		abort();
	}
	return class_dropped;
}