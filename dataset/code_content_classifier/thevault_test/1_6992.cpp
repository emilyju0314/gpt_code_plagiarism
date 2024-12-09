void QA::drain_buf(double* DrainArr, double bufToDrain, 
		   double* FinalDrainArray, double* bufAvail, 
		   int layers, double rate, double srtt)
{
	double bufReq1, bufReq2, bufs1[MAX_LAYER], bufs2[MAX_LAYER], slope, 
		extra, targetArr[MAX_LAYER], maxDrainRemain;
	int bs1, bs2, l;

	slope = seg_size_/srtt;
	bs1 = MAXBKOFF_ + 1;
	bs2 = MAXBKOFF_ + 1;
	bufReq1 = bufReq2 = 0;
	for(l=0; l<layers; l++){
		bufReq1 += bufOptScen1(l, layers, rate, slope, bs1);
		bufReq2 += bufOptScen2(l, layers, rate, slope, bs2);
	} 

	for(l=0; l<MAX_LAYER; l++){
		bufs1[l] = 0;
		bufs2[l] = 0;
		DrainArr[l] = 0.0;
	}

	while(bufReq1 > TotalBuf(layers, bufAvail)){
		bufReq1 = 0;
		bs1--;
		for(l=0; l<layers; l++){
			bufs1[l] = bufOptScen1(l, layers, rate, slope, bs1);
			bufReq1 += bufs1[l];
		} 
	}
  
	while(bufReq2 > TotalBuf(layers, bufAvail)){
		bufReq2 = 0;
		bs2--;
		for(l=0; l<layers; l++){
			bufs2[l] =  bufOptScen2(l, layers, rate, slope, bs2);
			bufReq2 += bufs2[l];
		} 
	}

	if (bufReq1 >= bufReq2) {
		// drain toward last optimal scenario 1
		for (l=layers-1; l>=0; l--){
			// we try to drain the maximum amount from
			// min no of highest layers
			// note that there is a limit on total draining
			// from a layer
			maxDrainRemain = srtt*LAYERBW_ - FinalDrainArray[l];
			if ((bufAvail[l] > bufs1[l] + maxDrainRemain) &&
			    (bufToDrain >= maxDrainRemain)) {
				DrainArr[l] = maxDrainRemain;
				bufToDrain -= maxDrainRemain;
			} else {
				if(bufAvail[l] > bufs1[l] + maxDrainRemain){
					DrainArr[l] = bufToDrain;
					bufToDrain = 0.0;
				} else {
					DrainArr[l] = bufAvail[l] - bufs1[l];
					bufToDrain -= bufAvail[l] - bufs1[l];

					/* for debug */
					if(DrainArr[l] < 0.0){
// 	    panic("# ERROR, DrainArr[%d]: %.2f, bufAvail: %.2f, bufs1: %.2f\n",
// 		  l, DrainArr[l], bufAvail[l], bufs1[l]);
						DrainArr[l] = 0.0;
					}
				}
			}
			if(bufToDrain == 0.0)
				return;
		}
		return;
	} else {   /* if (bufReq1 >= bufReq2) */

		// Drain towards he last optima scenario 2 
		// We're draining - don't care about the upper bound on 
		// scenario 2.
		// Have to calculate all the layers together to get this max 
		// thing to work
		extra = 0.0;
		// Calculate the extra buffering 
		for (l=0; l<layers; l++) {
			if(bufs1[l] > bufs2[l])
				extra += bufs1[l] - bufs2[l];
		}

		for (l=layers-1; l>=0; l--)
			if(bufs1[l] >= bufs2[l])
				targetArr[l] = bufs1[l];
			else
				if (bufs2[l] - bufs1[l] >= extra) {
					targetArr[l] = bufs2[l] - extra;
					extra = 0;
				} else {
					// there is enough extra to compenstae the dif
					if (extra > 0) {
						targetArr[l] = bufs2[l];
						extra -= bufs2[l] - bufs1[l];
					} else 
						panic("# ERROR Should not \
reach here, extra: %.2f, bufs2: %.2f, bufs1: %.2f, L%d\n", 
						extra, bufs2[l], bufs1[l], l);
				}
	} /* end of if (bufReq1 >= bufReq2) */
   
	// drain toward last optimal scenario 2
	for (l=layers-1; l>=0; l--) {
		// we try to drain the maximum amount from
		// min no of highest layers
		// note that there is a limit on total draining
		// from a layer
		maxDrainRemain = srtt*LAYERBW_ - FinalDrainArray[l];
		if ((bufAvail[l] > targetArr[l] + maxDrainRemain) &&
		    (bufToDrain >= maxDrainRemain)) {
			DrainArr[l] = maxDrainRemain;
			bufToDrain -= maxDrainRemain;
		} else {
			if(bufAvail[l] > targetArr[l] + maxDrainRemain){
				DrainArr[l] = bufToDrain;
				bufToDrain = 0.0;
			} else {
				DrainArr[l] = bufAvail[l] - targetArr[l];
				bufToDrain -= bufAvail[l] - targetArr[l];
	
				// for debug 
				if (DrainArr[l] < 0.0) {
// 	  panic("# ERROR, DrainArr[%d]: %.2f, bufAvail: %.2f, bufs1: %.2f\n",
// 		l, DrainArr[l], bufAvail[l], bufs1[l]);
					DrainArr[l] = 0;
				}
			}
		}
		if (bufToDrain == 0.0)
			return;
	} /* end of for */
	return;
}