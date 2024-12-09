void MosaicGridTool::onProjectionChanged() {
    TProjection * tproj = (TProjection *)getWidget()->getProjection();
    
    // If Projection changed from a file, force extents to come from 
    // the new map file
    m_latExtents = Map;
    m_lonExtents = Map; 

    Latitude minLat = Latitude(tproj->MinimumLatitude(), Angle::Degrees);
    Latitude maxLat = Latitude(tproj->MaximumLatitude(), Angle::Degrees);
    
    setLatExtents(m_latExtents, minLat, maxLat);
  
    Longitude minLon = Longitude(tproj->MinimumLongitude(), Angle::Degrees);
    Longitude maxLon = Longitude(tproj->MaximumLongitude(), Angle::Degrees);
  
    setLonExtents(m_lonExtents, minLon, maxLon);
  }