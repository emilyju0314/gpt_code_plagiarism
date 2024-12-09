void MosaicGridTool::setLatExtents(GridExtentSource source,
                                     Latitude minLat = Latitude(),
                                     Latitude maxLat = Latitude()) {
    m_latExtents = source;

    Projection *proj = getWidget()->getProjection();
    if (proj && proj->projectionType() == Projection::Triaxial) {
      TProjection *tproj = (TProjection *) proj;
      PvlGroup mappingGroup(tproj->Mapping());

      Distance equatorialRadius(tproj->EquatorialRadius(),
                                Distance::Meters);
      Distance polarRadius(tproj->PolarRadius(), Distance::Meters);

      QRectF boundingRect = getWidget()->cubesBoundingRect();

      double topLeft = 100;
      double topRight = 100;
      double bottomLeft = 100;
      double bottomRight = 100;
      bool cubeRectWorked = true;

      switch (source) {

        case Map:
          m_minLat = Latitude(tproj->MinimumLatitude(), mappingGroup, Angle::Degrees);
          m_maxLat = Latitude(tproj->MaximumLatitude(), mappingGroup,  Angle::Degrees);
          break;

        case Cubes:
          if (tproj->SetCoordinate(boundingRect.topLeft().x(), -boundingRect.topLeft().y())) {
            topLeft = tproj->Latitude();
          }
          else {
            cubeRectWorked = false;
          }
          if (tproj->SetCoordinate(boundingRect.topRight().x(), -boundingRect.topRight().y())) {
            topRight = tproj->Latitude();
          }
          else {
            cubeRectWorked = false;
          }
          if (tproj->SetCoordinate(boundingRect.bottomLeft().x(), -boundingRect.bottomLeft().y())) {
            bottomLeft = tproj->Latitude();
          }
          else {
            cubeRectWorked = false;
          }
          if (tproj->SetCoordinate(boundingRect.bottomRight().x(),
              -boundingRect.bottomRight().y())) {
            bottomRight = tproj->Latitude();
          }
          else {
            cubeRectWorked = false;
          }

          if (cubeRectWorked) {
            m_minLat = Latitude(std::min(std::min(topLeft, topRight),
                                        std::min(bottomLeft, bottomRight)), mappingGroup,
                                Angle::Degrees);
            m_maxLat = Latitude(std::max(std::max(topLeft, topRight),
                                        std::max(bottomLeft, bottomRight)), mappingGroup,
                                Angle::Degrees);

            if (tproj->SetUniversalGround(-90.0, 0) &&
                boundingRect.contains(QPointF(tproj->XCoord(), -tproj->YCoord()))) {
              m_minLat = Latitude(-90.0, mappingGroup, Angle::Degrees);
            }

            if (tproj->SetUniversalGround(90.0, 0) &&
                boundingRect.contains(QPointF(tproj->XCoord(), -tproj->YCoord()))) {
              m_maxLat = Latitude(90.0, mappingGroup, Angle::Degrees);
            }
          }
          else {
            m_minLat = Latitude(-90, mappingGroup, Angle::Degrees);
            m_maxLat = Latitude(90, mappingGroup, Angle::Degrees);
            m_latExtents = Manual;

            static Projection *lastProjWithThisError = NULL;

            if (proj != lastProjWithThisError) {
              lastProjWithThisError = proj;
              QMessageBox::warning(NULL, tr("Latitude Extent Failure"),
                                   tr("<p/>Could not extract latitude extents from the cubes.<br/>"
                                      "<br/>The option <strong>\"Compute From Images\"</strong> "
                                      "will default to using the <strong>Manual</strong> option "
                                      "for latitude extents with a range of -90 to 90."));
            }
          }
          break;

        case Manual:
          m_minLat = Latitude(minLat);
          m_maxLat = Latitude(maxLat);
          break;

        default:
          m_minLat = Latitude(tproj->MinimumLatitude(), mappingGroup, Angle::Degrees);
          m_maxLat = Latitude(tproj->MaximumLatitude(), mappingGroup, Angle::Degrees);
      }
    }
  }