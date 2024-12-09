void QA::DrainPacket(double bufToDrain, double* FinalDrainArray, int layers,
		     double rate, double srtt, double* FinalBuffer)
{
	double DrainArr[MAX_LAYER],  bufAvail[MAX_LAYER], TotBufAvail;
	int l,cnt;
  
	for(l=0; l<MAX_LAYER; l++){
		FinalDrainArray[l] = 0.0;
		bufAvail[l] = buffer_[l];
	}

	TotBufAvail = TotalBuf(layers, bufAvail);
	cnt = 0;
	while ((bufToDrain > 0) && (cnt < 10)) {
		// debug("bufToDrain%d: %.2f\n", cnt, bufToDrain);
		drain_buf(DrainArr, bufToDrain, FinalDrainArray, bufAvail, 
			  layers, rate, srtt);
		
		for(l=0; l<layers; l++){
			bufToDrain -= DrainArr[l];
			TotBufAvail -= DrainArr[l];
			FinalDrainArray[l] += DrainArr[l];
			bufAvail[l] -= DrainArr[l];
			FinalBuffer[l] = buffer_[l] - FinalDrainArray[l];
		}
		cnt++;
	}
}