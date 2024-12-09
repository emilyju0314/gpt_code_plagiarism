double TrackCaloIntersectionMVA::scanIn(Calorimeter const& cal, TrkDifTraj const& traj, HelixTraj const& trkHel, int iSection, double rangeStart, double rangeEnd)
    {         

	 //check if we're inside the rdial envelope, if not, fast forward to it
	 double initRadius = radiusAtRange(traj,rangeStart);
	 


	 if (initRadius < cal.disk(iSection).geomInfo().innerEnvelopeR())  rangeStart += extendToRadius(trkHel, traj, rangeStart, cal.disk(iSection).geomInfo().innerEnvelopeR());	 
	 if (initRadius > cal.disk(iSection).geomInfo().outerEnvelopeR()) rangeStart += extendToRadius(trkHel, traj, rangeStart, cal.disk(iSection).geomInfo().outerEnvelopeR()); 

	 if (rangeStart > rangeEnd) return rangeEnd+1e-4;


	 //now find two starting points, one inside the boundary, the other outside
	 CLHEP::Hep3Vector trjVec;
	 updateTrjVec(cal,traj,rangeStart,trjVec);
	 
	 double rangeIn(rangeStart),rangeOut(rangeStart);
	 if ( cal.geomUtil().isInsideSection(iSection,trjVec))
	 {
	      while (cal.geomUtil().isInsideSection(iSection,trjVec))
	      {
		 rangeIn = rangeOut; 
		 rangeOut -= _pathStep;
		 updateTrjVec(cal,traj,rangeOut,trjVec);
		 if (_diagLevel>2) std::cout<<"TrackExtrpol position scan In down "<<trjVec<<"  for currentRange="<<rangeOut<<"   "<<"radius="<<radiusAtRange(traj,rangeOut)<<std::endl;
	      }	 

	 } else {
	 
	      while ( !cal.geomUtil().isInsideSection(iSection,trjVec) )
	      {
		 rangeOut = rangeIn; 
		 rangeIn += _pathStep;
        	 updateTrjVec(cal,traj,rangeIn,trjVec);
		 if (_diagLevel>2) std::cout<<"TrackExtrpol position scan In up "<<trjVec<<"  for currentRange="<<rangeIn<<"   "<<"radius="<<radiusAtRange(traj,rangeIn)<<std::endl;

		 if ( rangeIn > rangeEnd) return rangeIn;
	      }	    
	 }
	 
	 //finally, run the binary search for the intersection
	 return scanBinary(cal, traj, iSection, rangeIn, rangeOut);
    }