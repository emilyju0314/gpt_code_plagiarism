double TrackCaloIntersectionMVA::scanOut(Calorimeter const& cal, TrkDifTraj const& traj, HelixTraj const& trkHel, int iSection, double rangeStart, double rangeEnd)
    {         

	 double range(rangeStart);
	 CLHEP::Hep3Vector trjVec;
	 updateTrjVec(cal,traj,range,trjVec);

         while ( cal.geomUtil().isInsideSection(iSection,trjVec) )
	 {         	    
	    range += _pathStep;
	    updateTrjVec(cal,traj,range,trjVec);
	    if (_diagLevel>2) std::cout<<"TrackExtrpol position scan Out up "<<trjVec<<"  for currentRange="<<range<<"   "<<"radius="<<radiusAtRange(traj,range)<<std::endl;	 	 
	 }

	 return scanBinary(cal, traj, iSection, range - _pathStep, range);
    }