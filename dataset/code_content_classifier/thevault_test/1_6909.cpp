void JoBS::updateError() {
	int i;
	int activeClasses, backloggedClasses;
	double meanWeightedDelay;

	meanWeightedDelay = 0;
	activeClasses = 0 ; 
	backloggedClasses = 0;
	
	for (i = 1; i <= NO_CLASSES; i++) 
		if (cls_[i]->head() != NULL) {
			backloggedClasses++;
			if (concerned_RDC_[i]) {
				meanWeightedDelay += prod_others_[i]*projDelay(i);
				activeClasses ++;
			}    
		}

	if (activeClasses > 0) 
		meanWeightedDelay /= (double)activeClasses;
	else if (backloggedClasses == 0) {
		fprintf(stderr, "JoBS::updateError() called but there's no backlog!\n");
		abort();
	}
	
	for (i = 1; i <= NO_CLASSES; i++) 
		if ((cls_[i]->head() != NULL)&&(concerned_RDC_[i])) {
			error_[i] = meanWeightedDelay-prod_others_[i]*projDelay(i);
		} else {
			error_[i] = 0.0; // either the class isn't concerned, or it's not backlogged
			// in any case, the rate shouldn't be adjusted.
		}
	return;
}