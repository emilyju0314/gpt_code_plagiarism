bool RobustHelixFit::fillArrayDz(RobustHelixFinderData& HelixData, std::vector<int> &hist, float &bin_size, float &start_dz){
    ComboHit*      hitP1(0), *hitP2(0);
    uint16_t       facezF1(0), facezF2(0);
    int            nHits(HelixData._chHitsToProcess.size());
    unsigned       counter = 0;
    
    for (int f1=0; f1<nHits-1; ++f1){
      hitP1   = &HelixData._chHitsToProcess[f1];
      if (!use(*hitP1))            continue;
      facezF1 = hitP1->strawId().uniqueFace();
	    
      for (int f2=f1+1; f2<nHits; ++f2){
	hitP2 = &HelixData._chHitsToProcess[f2];
	if (!use(*hitP2))          continue;

	facezF2 = hitP2->strawId().uniqueFace();
	if ( facezF1 == facezF2 )  continue;

	float dz = fabs(hitP2->pos().z() - hitP1->pos().z());

	//increment the hist array in the correct position
	int i = (dz-start_dz)/bin_size;
	if (i < _initFZFrequencyArraySize)  {
	  hist[i] = hist[i] + 1.;
	  ++counter;
	}
      }//end secondloop over the hits
    }//end first loop over the hits
     
    return (counter >= _minnhit);
  }