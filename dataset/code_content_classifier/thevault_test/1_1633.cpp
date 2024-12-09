PvlObject MosaicGridTool::toPvl() const {
    PvlObject obj(projectPvlObjectName());

    obj += PvlKeyword("ShouldCheckBoxes", toString((int)m_shouldCheckBoxes));

    obj += PvlKeyword("BaseLatitude", toString(m_baseLat.degrees()));
    obj += PvlKeyword("BaseLongitude", toString(m_baseLon.degrees()));

    obj += PvlKeyword("LatitudeIncrement", toString(m_latInc.degrees()));
    obj += PvlKeyword("LongitudeIncrement", toString(m_lonInc.degrees()));

    obj += PvlKeyword("LatitudeExtentType", toString(m_latExtents));
    obj += PvlKeyword("MaximumLatitude", toString(m_maxLat.degrees()));
    obj += PvlKeyword("MinimumLongitude", toString(m_minLon.degrees()));

    obj += PvlKeyword("LongitudeExtentType", toString(m_lonExtents));
    obj += PvlKeyword("MinimumLatitude", toString(m_minLat.degrees()));
    obj += PvlKeyword("MaximumLongitude", toString(m_maxLon.degrees()));

    obj += PvlKeyword("Density", toString(m_density));
    obj += PvlKeyword("Visible", toString((int)(m_gridItem != NULL)));

    return obj;
  }