void MosaicGridTool::fromPvl(const PvlObject &obj) {

    Projection *proj = getWidget()->getProjection();
    if (proj && proj->projectionType() == Projection::Triaxial) {
      TProjection *tproj = (TProjection *) proj;
      Distance equatorialRadius(
          tproj->EquatorialRadius(),
          Distance::Meters);
      Distance polarRadius(
          tproj->PolarRadius(), Distance::Meters);

      if (obj["BaseLatitude"][0] != "Null")
        m_baseLat = Latitude(toDouble(obj["BaseLatitude"][0]), equatorialRadius, polarRadius,
                             Latitude::Planetocentric, Angle::Degrees);

      if (obj["BaseLongitude"][0] != "Null")
        m_baseLon = Longitude(toDouble(obj["BaseLongitude"][0]), Angle::Degrees);

      if (obj["LatitudeIncrement"][0] != "Null")
        m_latInc = Angle(toDouble(obj["LatitudeIncrement"][0]), Angle::Degrees);

      if (obj["LongitudeIncrement"][0] != "Null")
        m_lonInc = Angle(toDouble(obj["LongitudeIncrement"][0]), Angle::Degrees);

      if (obj.hasKeyword("LatitudeExtentType")) {
        if (obj["LatitudeExtentType"][0] != "Null")
          m_latExtents = (GridExtentSource)toInt(obj["LatitudeExtentType"][0]);
      }

      if (obj.hasKeyword("MinimumLatitude")) {
        if (obj["MinimumLatitude"][0] != "Null")
          m_minLat = Latitude(toDouble(obj["MinimumLatitude"][0]), equatorialRadius, polarRadius,
                              Latitude::Planetocentric, Angle::Degrees);
      }

      if (obj.hasKeyword("MaximumLatitude")) {
        if (obj["MaximumLatitude"][0] != "Null")
          m_maxLat = Latitude(toDouble(obj["MaximumLatitude"][0]), equatorialRadius, polarRadius,
                              Latitude::Planetocentric, Angle::Degrees);
      }

      if (obj.hasKeyword("LongitudeExtentType")) {
        if (obj["LongitudeExtentType"][0] != "Null")
          m_lonExtents = (GridExtentSource)toInt(obj["LongitudeExtentType"][0]);
      }

      if (obj.hasKeyword("MinimumLongitude")) {
        if (obj["MinimumLongitude"][0] != "Null")
          m_minLon = Longitude(toDouble(obj["MinimumLongitude"][0]), Angle::Degrees);
      }

      if (obj.hasKeyword("MaximumLongitude")) {
        if (obj["MaximumLongitude"][0] != "Null")
          m_maxLon = Longitude(toDouble(obj["MaximumLongitude"][0]), Angle::Degrees);
      }

      if (obj["Density"][0] != "Null")
        m_density = toDouble(obj["Density"][0]);


      if (obj.hasKeyword("CheckTheBoxes")) {
        if (obj["CheckTheBoxes"][0] != "Null") {
          m_shouldCheckBoxes = (obj["CheckTheBoxes"][0] == "true");
        }
      }

      if(toBool(obj["Visible"][0])) {
        drawGrid();
      }
    }
  }