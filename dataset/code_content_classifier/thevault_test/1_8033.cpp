int DeltaFinder::orderHits() {
    ChannelID cx, co;

    int nhits = _chcol->size();
    for (int h=0; h<nhits; ++h) {
      const ComboHit*         sh  = &(*_chcol)[h];

      if (sh->energyDep() > _maxElectronHitEnergy)         continue;
      if ( (sh->time() < _minT) || (sh->time() > _maxT) )  continue;

      cx.Station                 = sh->strawId().station();  //straw->id().getStation();
      cx.Plane                   = sh->strawId().plane() % 2;//straw->id().getPlane() % 2;
      cx.Face                    = -1;
      cx.Panel                   = sh->strawId().panel();    //straw->id().getPanel();
      cx.Layer                   = sh->strawId().layer();    //straw->id().getLayer();

					      // get Z-ordered location
      orderID(&cx, &co);

      int os       = co.Station;
      int of       = co.Face;
      int op       = co.Panel;
      int ol       = co.Layer;

      if (_useTimePeaks == 1) {
        bool               intime(false);
        int                nTPeaks  = _tpeakcol->size();
        double             hitTime  = sh->time();
        const CaloCluster* cl(nullptr);
        int                iDisk(-1);

        for (int i=0; i<nTPeaks; ++i){
          cl    = _tpeakcol->at(i).caloCluster().get();
          if (cl == nullptr) {
            printf(">>> DeltaFinder::orderHits() no CaloCluster found within the time peak %i\n", i);
            continue;
          }
          iDisk = cl->diskID();
          double    dt = cl->time() - (hitTime + _stationToCaloTOF[iDisk][os]);
          if ( (dt < _maxCaloDt) && (dt > _minCaloDt) ) {
            intime = true;
            break;
          }
        }
        if (!intime)                                    continue;
      }

      PanelZ_t* pz = &_data.oTracker[os][of][op];

      if ((os < 0) || (os >= kNStations     )) printf(" >>> ERROR: wrong station number: %i\n",os);
      if ((of < 0) || (of >= kNFaces        )) printf(" >>> ERROR: wrong face    number: %i\n",of);
      if ((op < 0) || (op >= kNPanelsPerFace)) printf(" >>> ERROR: wrong panel   number: %i\n",op);
      if ((ol < 0) || (ol >= 2              )) printf(" >>> ERROR: wrong layer   number: %i\n",ol);

      float sigw = sh->posRes(ComboHit::wire);// shp->posRes(StrawHitPosition::wire);
      pz->fHitData.push_back(HitData_t(sh,/*shp,straw,*/sigw));
    }

    return 0;
  }