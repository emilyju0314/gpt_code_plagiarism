void BFieldPlotter::fillHistogram(BFMap const *map, art::ServiceHandle<art::TFileService> tfs) {
    GeomHandle<DetectorSystem> det;
    //define histogram binning such that map edges are bin centers and inside histogram
    long nbinsOne = std::lround((_axisOneMax - _axisOneMin)/_mapBinSize) + 1;
    long nbinsTwo = std::lround((_axisTwoMax - _axisTwoMin)/_mapBinSize) + 1;
    //check that the map bin step size works with the edges given
    if(nbinsOne > 1 && std::abs(_axisOneMin + (nbinsOne-1)*_mapBinSize - _axisOneMax > (_axisOneMax-_axisOneMin)/(100.*(nbinsOne-1))))
      throw cet::exception("BADCONFIG") << "BField mapping axis values not steppable with step size given: "
        << _axisOneMin << " < axisOneValues < " << _axisOneMax << ", "
        << "step size = " << _mapBinSize;

    if(nbinsTwo > 1 && std::abs(_axisTwoMin + (nbinsTwo-1)*_mapBinSize - _axisTwoMax > (_axisTwoMax-_axisTwoMin)/(100.*(nbinsTwo-1))))
      throw cet::exception("BADCONFIG") << "BField mapping axis values not steppable with step size given: "
        << _axisTwoMin << " < axisTwoValues < " << _axisTwoMax << ", "
        << "step size = " << _mapBinSize;

    //if a null map, plot the default field from the manager
    const std::string name = (map) ? map->getKey() : "default";
    if(_hMap[name]) return; //already filled the maps in a previous event

    // if dumping, create the file
    std::ofstream fs;
    if(_dump){
      string dumpfile= name+_dumpname+".csv";
      fs.open (dumpfile.c_str(), fstream::out);
      if(fs.is_open()){
        fs << "# Dump of " << name << endl;
        fs <<  "#  x   ,  y   ,   z   ,  Bx   ,  By   ,  Bz" << endl;
      } else
        throw cet::exception("BADCONFIG") << "Cannot open file " << dumpfile << endl;
    }

    //make a directory for the map
    art::TFileDirectory tfdir = tfs->mkdir( ("BFieldMapper_"+name).c_str() );

    //define a histogram
    _hMap[name] = tfdir.make<TH2F>(("hMap"+name).c_str()  , (name + " Magnetic field map").c_str(),
        // add offsets so all values are bin centers and fit edge into the map
        nbinsOne, _axisOneMin - _mapBinSize/2.,_axisOneMax + _mapBinSize/2.,
        nbinsTwo, _axisTwoMin - _mapBinSize/2.,_axisTwoMax + _mapBinSize/2.);

    GeomHandle<BFieldManager> bf; //only needed in null map case
    //Loop through the points in the magnetic field
    double axisOne, axisTwo;
    for(int binOne = 0; binOne < nbinsOne; ++binOne) {
      axisOne = _axisOneMin + binOne*_mapBinSize;
      if(binOne == 0 || binOne == nbinsOne-1) //if first or last bin, at slight step into map to avoid edge issues
        axisOne += (binOne) ? -_mapBinSize/100. : _mapBinSize/100.;
      for(int binTwo = 0; binTwo < nbinsTwo; ++binTwo) {
        axisTwo = _axisTwoMin + binTwo*_mapBinSize;
        if(binTwo == 0 || binTwo == nbinsTwo-1) //if first or last bin, at slight step into map to avoid edge issues
          axisTwo += (binTwo) ? -_mapBinSize/100. : _mapBinSize/100.;
        CLHEP::Hep3Vector point;
        CLHEP::Hep3Vector field;
        if(_plane == "x")
          point = CLHEP::Hep3Vector(_planeValue, axisOne, axisTwo);
        else if(_plane == "y")
          point = CLHEP::Hep3Vector(axisOne, _planeValue, axisTwo);
        else if(_plane == "z")
          point = CLHEP::Hep3Vector(axisOne, axisTwo, _planeValue);
        if(map)
          map->getBFieldWithStatus(point,field);
        else //if null, get the manager and plot the field returned by it
          bf->getBFieldWithStatus(point,field);

        _hMap[name]->Fill(axisOne, axisTwo, field.mag()); //fill with weight of the field magnitude

        // if there's a dump file, fill it.
        if(_dump){
          CLHEP::Hep3Vector dpoint = _detector ? det->toDetector(point) : point;
          fs <<  std::setw(10) << std::setprecision(5)
            << dpoint.x() << ", " << std::setprecision(5)
            << dpoint.y() << ", " << std::setprecision(5)
            << dpoint.z() << ", " << std::setprecision(5)
            << field.x() << ", " << std::setprecision(5)
            << field.y() << ", " << std::setprecision(5)
            << field.z() << endl;
        }

      } //end axis two loop
    } //end axis one loop
    if(_dump && fs.is_open())fs.close();
  }