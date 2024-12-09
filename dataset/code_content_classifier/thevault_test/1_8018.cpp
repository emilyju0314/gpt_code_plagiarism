void DeltaFinder2::beginRun(art::Run& aRun) {
    mu2e::GeomHandle<mu2e::Tracker> ttHandle;
    _tracker      = ttHandle.get();
    _data.tracker = _tracker;
    
    mu2e::GeomHandle<mu2e::DiskCalorimeter> ch;
    _calorimeter = ch.get();

    ChannelID cx, co;
    int       nDisks    = _calorimeter->nDisk();
    double    disk_z[2] = {0};//given in the tracker frame

    for (int i=0; i<nDisks; ++i){ 
      Hep3Vector gpos = _calorimeter->disk(i).geomInfo().origin();
      Hep3Vector tpos = _calorimeter->geomUtil().mu2eToTracker(gpos);
      disk_z[i] = tpos.z();
    }

    int       nPlanesPerStation(2);
    double    station_z(0);

    for (unsigned planeId=0; planeId<_tracker->nPlanes(); planeId++) {
      const Plane* pln = &_tracker->getPlane(planeId);
      int  ist = planeId/nPlanesPerStation;
      int  ipl = planeId % nPlanesPerStation;

      //calculate the time-of-flight between the station and each calorimeter disk
      //for a typical Conversion Electron
      if (ipl == 0) {
	station_z = pln->origin().z();
      }else {
	station_z = (station_z + pln->origin().z())/2.;
	for (int iDisk=0; iDisk<nDisks; ++iDisk){
	  _stationToCaloTOF[iDisk][ist] = (disk_z[iDisk] - station_z)/sin(_pitchAngle)/CLHEP::c_light;
	}
      }

      for (size_t ipn=0; ipn<pln->nPanels(); ipn++) {
	const Panel* panel = &pln->getPanel(ipn);
	int face;
	if (panel->id().getPanel() % 2 == 0) face = 0;
	else                                 face = 1;
	for (unsigned il=0; il<panel->nLayers(); ++il) {
	  cx.Station = ist;
	  cx.Plane   = ipl;
	  cx.Face    = face;
	  cx.Panel   = ipn;
	  cx.Layer   = il;
	  orderID (&cx, &co);
	  int os = co.Station; 
	  int of = co.Face;
	  int op = co.Panel;
	  PanelZ_t* pz = &_data.oTracker[os][of][op];
	  pz->fPanel = panel;
	  //-----------------------------------------------------------------------------
	  // panel caches phi of its center and the z
	  //-----------------------------------------------------------------------------
	  pz->wx  = panel->straw0Direction().x();
	  pz->wy  = panel->straw0Direction().y();
	  pz->phi = panel->straw0MidPoint().phi();
	  pz->z   = (panel->getStraw(0).getMidPoint().z()+panel->getStraw(1).getMidPoint().z())/2.;
	}
      }	

      // if ((ist == 6) || (ist == 13))  _data.stationUsed[ist] = 0;
      // else                            _data.stationUsed[ist] = 1;
    }
//-----------------------------------------------------------------------------
// it is enough to print that once
//-----------------------------------------------------------------------------
    if (_testOrder && (_testOrderPrinted == 0)) {
      testOrderID  ();
      testdeOrderID();
      _testOrderPrinted = 1;
    }

    if (_diagLevel != 0) _hmanager->debug(&_data,1);
  }