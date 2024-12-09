void MosaicGridTool::autoGrid(bool draw) {

    QSettings settings(
        FileName(QString("$HOME/.Isis/%1/mosaicSceneGridTool.config")
            .arg(QApplication::applicationName())).expanded(),
        QSettings::NativeFormat);
    settings.setValue("autoGrid", draw);

    Projection *proj = getWidget()->getProjection();
    if (draw && proj && proj->projectionType() == Projection::Triaxial) {
      TProjection *tproj = (TProjection *) proj;
      QRectF boundingRect = getWidget()->cubesBoundingRect();

      if (!boundingRect.isNull()) {

        setLatExtents(m_latExtents, m_minLat, m_maxLat);
        setLonExtents(m_lonExtents, m_minLon, m_maxLon);

        double latRange = m_maxLat.degrees() - m_minLat.degrees();

        if (tproj->Mapping()["LatitudeType"][0] == "Planetographic") {
          latRange =
              m_maxLat.planetographic(Angle::Degrees) - m_minLat.planetographic(Angle::Degrees);
        }

        double lonRange = m_maxLon.degrees() - m_minLon.degrees();

        /*
         * To calculate the lat/lon increments we divide the range by 10 (so we end up
         *   with about 10 sections in the range, whatever the extents may be) and we
         *   divide that by 1, 10, 100,... depending on the log10 of the range. We then
         *   round this value and multiply but the same number that we divided  by. This
         *   gives us a clear, sensible value for an increment.
         *
         *   Example Increments:
         *     Range = 1    --> Inc = .1
         *     Range = 10   --> Inc = 1
         *     Range = 100  --> Inc = 10
         *     Range = 5000 --> Inc = 500
         *
         *   inc = round[(range/10) / 10^floor(log(range) - 1)] * 10^floor(log(range) - 1)
         */

        double latOffsetMultiplier = pow(10, qFloor(log10(latRange) - 1));
        double lonOffsetMultiplier = pow(10, qFloor(log10(lonRange) - 1));

        double idealLatInc = latRange / 10.0;
        double idealLonInc = lonRange / 10.0;

        double roundedLatInc = qRound(idealLatInc / latOffsetMultiplier) * latOffsetMultiplier ;
        double roundedLonInc = qRound(idealLonInc / lonOffsetMultiplier) * lonOffsetMultiplier ;

        m_latInc = Angle(roundedLatInc, Angle::Degrees);
        m_lonInc = Angle(roundedLonInc, Angle::Degrees);

        m_previousBoundingRect = boundingRect;

        drawGrid();
      }
    }
  }