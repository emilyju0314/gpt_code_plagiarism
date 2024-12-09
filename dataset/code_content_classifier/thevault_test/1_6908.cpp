double* JoBS::adjustRatesRDC() {
	int i, j;
	int RDC_Classes, activeClasses;
	double* result;
	double credit, available, lower_bound, upper_bound;
	double bk;
	
	activeClasses = 0;
	RDC_Classes = 0;

	upper_bound = link_ -> bandwidth();

	for (i = 1; i <= NO_CLASSES; i++)
		if (cls_[i]->head() != NULL) {
			activeClasses++;
			if (concerned_RDC_[i]) 
				RDC_Classes++;
			else 
				upper_bound -= service_rate_[i];
		}

	result = new double[NO_CLASSES+1];

	if (result == NULL) 
		return NULL;

	for (i = 0; i <= NO_CLASSES; i++) 
		result[i] = 0;

	if (upper_bound < PRECISION_ERROR || activeClasses == 0) return result;
	
	credit = 0;
	lower_bound = 0;
	
	updateError();
	min_share_ = 1.0;
	bk = 0;
	
	for (i = 1; i <= NO_CLASSES; i++) 
		if (concerned_RDC_[i])
			bk += Rin_[i];

	for (i = 1; i <= NO_CLASSES; i++) 
		if ((double)Rin_[i]/(double)bk < min_share_)
			min_share_ = (double)Rin_[i]/(double)bk;
  
	/*
	 * note that the formula for Kp is slightly different 
	 * from the formula derived in CS-2001-21. 
	 * the formula used here provides better results 
	 * at the expense of more complicated computations.
	 */
	
	Kp_dynamic_ = Kp_static_*pow(upper_bound, 2.)*min_share_*util_*max(util_, 1.0);

	credit = 0;
	for (i = 1; i <= NO_CLASSES; i++) {
		if ((cls_[i]->head() != NULL)&&(concerned_RDC_[i])) {
			result[i] = Kp_dynamic_*(error_[i]); 
		}
	}

	// saturation 

	for (i = 1; i <= NO_CLASSES; i++) 
		if (cls_[i]->head() != NULL) {
			if (concerned_RDC_[i]) {
				lower_bound += max(0, min_rate_[i]);
			} 
		}

	for (i = 1; i <= NO_CLASSES; i++) {
		if ((concerned_RDC_[i])&&(result[i] + service_rate_[i] > upper_bound)) {
			for (j = 0; j <= NO_CLASSES; j++) {
				if (concerned_RDC_[j]) {
					if (j == i) 
						result[j] = (upper_bound-service_rate_[j])  
						    + min_rate_[j] - lower_bound;
					else
						result[j] = -service_rate_[j]+min_rate_[j];
				}
			}
			return result;
		}
		if (concerned_RDC_[i] && result[i] + service_rate_[i] < min_rate_[i]) {
			credit += service_rate_[i]+result[i]-min_rate_[i]; 
			// "credit" is in fact a negative number
			result[i] = -service_rate_[i]+min_rate_[i];
		}
	}

	for (i = NO_CLASSES; (i > 0)&&(credit < 0); i--) {
		if ((cls_[i]->head() != NULL)&&(concerned_RDC_[i])) {
			available = result[i] + service_rate_[i]-min_rate_[i];
			if (available >= -credit) {
				result[i] += credit;
				credit = 0;
			} else {
				result[i] -= available;
				credit += available;
			}      
		}
	}
	return result;
}