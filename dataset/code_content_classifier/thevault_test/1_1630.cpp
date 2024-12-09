void MosaicGridTool::setLonExtents(GridExtentSource source,
                                     Longitude minLon = Longitude(),
                                     Longitude maxLon = Longitude()) {
    m_lonExtents = source;

    Projection *proj = getWidget()->getProjection();
    if (proj && proj->projectionType() == Projection::Triaxial) {
      TProjection * tproj = (TProjection *) proj;
      QRectF boundingRect = getWidget()->cubesBoundingRect();

      double topLeft = 0;
      double topRight = 0;
      double bottomLeft = 0;
      double bottomRight = 0;
      bool cubeRectWorked = true;

      switch (source) {

        case Map:
          m_minLon = Longitude(tproj->MinimumLongitude(), Angle::Degrees);
          m_maxLon = Longitude(tproj->MaximumLongitude(), Angle::Degrees);
          break;

        case Cubes:
          if (tproj->SetCoordinate(boundingRect.topLeft().x(), -boundingRect.topLeft().y())) {
            
            topLeft = tproj->Longitude();
          }
          else {
            cubeRectWorked = false;
          }
          if (tproj->SetCoordinate(boundingRect.topRight().x(), -boundingRect.topRight().y())) {
            topRight = tproj->Longitude();
          }
          else {
            cubeRectWorked = false;
          }
          if (tproj->SetCoordinate(boundingRect.bottomLeft().x(), -boundingRect.bottomLeft().y())) {
            bottomLeft = tproj->Longitude();
          }
          else {
            cubeRectWorked = false;
          }
          if (tproj->SetCoordinate(boundingRect.bottomRight().x(),
              -boundingRect.bottomRight().y())) {
            bottomRight = tproj->Longitude();
          }
          else {
            cubeRectWorked = false;
          }

          if (cubeRectWorked) {
            m_minLon = Longitude(std::min(std::min(topLeft, topRight),
                                          std::min(bottomLeft, bottomRight)),
                                Angle::Degrees);
            m_maxLon = Longitude(std::max(std::max(topLeft, topRight),
                                          std::max(bottomLeft, bottomRight)),
                                Angle::Degrees);
            if (m_minLon < domainMinLon()) {
              m_minLon = domainMinLon();
            }
            if (m_maxLon > domainMaxLon()) {
              m_maxLon = domainMaxLon();
            }
            //Draw 0-360 if the pole is in the cubes' bounding rectangle.
            if (m_minLat == Angle(-90.0, Angle::Degrees) ||
                m_maxLat == Angle(90.0, Angle::Degrees)) {
              m_minLon = domainMinLon();
              m_maxLon = domainMaxLon();
            }
          }
          else {
            m_minLon = domainMinLon();
            m_maxLon = domainMaxLon();
            m_lonExtents = Manual;

            static Projection *lastProjWithThisError = NULL;

            if (proj != lastProjWithThisError) {
              lastProjWithThisError = proj;
              QMessageBox::warning(NULL, tr("Longitude Extent Failure"),
                                   tr("<p/>Could not extract longitude extents from the cubes.<br/>"
                                      "<br/>The option <strong>\"Compute From Images\"</strong> "
                                      "will default to using the <strong>Manual</strong> option "
                                      "for longitude extents with a range of 0 to 360."));
            }
          }
          break;

        case Manual:
          m_minLon = minLon;
          m_maxLon = maxLon;
          break;

        default:
          m_minLon = Longitude(tproj->MinimumLongitude(), Angle::Degrees);
          m_maxLon = Longitude(tproj->MaximumLongitude(), Angle::Degrees);
      }
    }
  }