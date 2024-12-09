void SpectralPlotTool::getSpectralStatistics(QVector<double> &labels,
                                               QVector<Statistics> &data,
                                               MdiCubeViewport *viewport) {
    QList<QPoint> vertices = rubberBandTool()->vertices();

    if (vertices.size() < 1) return;

    double ss, sl, es, el, x, y;
    std::vector <int> x_contained, y_contained;

    // Convert vertices to their sub-pixel sample/line values
    viewport->viewportToCube(vertices[0].x(), vertices[0].y(), ss, sl);
    viewport->viewportToCube(vertices[2].x(), vertices[2].y(), es, el);

    // round the start and end sample/line sub-pixel points to the nearest int (pixel)
    ss = round(ss);
    sl = round(sl);
    es = round(es);
    el = round(el);

    // calculate number of samples will be in Brick's shape buffer with absolute value
    // in case user makes a rectangle from right to left
    int samps = ( std::abs(es - ss) + 1) ;
    Cube *cube = viewport->cube();
    Brick *brick = new Brick(*cube, samps, 1, 1);
    Pvl &pvl = *viewport->cube()->label();

    if (rubberBandTool()->currentMode() == RubberBandTool::PolygonMode) {
//       samps = 1;
      geos::geom::CoordinateSequence *pts = new geos::geom::CoordinateArraySequence();
      for (int i = 0; i < vertices.size(); i++) {
        viewport->viewportToCube(vertices[i].x(), vertices[i].y(), x, y);
        // add the x,y vertices (double) to the pts CoordinateSequence
        pts->add(geos::geom::Coordinate(x, y));
      }/*end for*/

      /*Add the first point again in order to make a closed line string*/
      viewport->viewportToCube(vertices[0].x(), vertices[0].y(), x, y);
      pts->add(geos::geom::Coordinate(x, y));

      geos::geom::Polygon *poly = globalFactory->createPolygon(
          globalFactory->createLinearRing(pts), NULL);

      const geos::geom::Envelope *envelope = poly->getEnvelopeInternal();

      // round the (double) max x's and y's and min x's and y's to the nearest pixel
      for (int y = (int)round(envelope->getMinY());
           y <= (int)round(envelope->getMaxY()); y++) {
        for (int x = (int)round(envelope->getMinX());
             x <= (int)round(envelope->getMaxX()); x++) {
          // create a point at the center of the pixel
          geos::geom::Coordinate c(x, y);
          geos::geom::Point *p = globalFactory->createPoint(c);
          // check if the center of the pixel is in the polygon's envelope (the selection)
          bool contains = p->within(poly);
          delete p;
          if (contains) {
            // these pixels will be used for computing statistics
            x_contained.push_back(x);
            y_contained.push_back(y);
          }

        } /*end x*/
      }/*end y*/

      delete poly;
      poly = NULL;
    }


    for (int band = 1; band <= cube->bandCount(); band++) {
      Statistics stats;

      /*Rectangle*/
      if (rubberBandTool()->currentMode() == RubberBandTool::RectangleMode) {
        for (int line = (int)std::min(sl, el); line <= (int)std::max(sl, el); line++) {
          // set Brick's base position at left-most endpoint
          brick->SetBasePosition(std::min(ss, es), line, band);
          cube->read(*brick);
          stats.AddData(brick->DoubleBuffer(), samps);
        }
      }

      /*Polygon*/
      if (rubberBandTool()->currentMode() == RubberBandTool::PolygonMode) {
        for (unsigned int j = 0; j < x_contained.size(); j++) {

          brick->SetBasePosition(x_contained[j], y_contained[j], band);
          cube->read(*brick);
          stats.AddData(*brick->DoubleBuffer());

        }
      }


      PlotCurve::Units targetUnits = (PlotCurve::Units)m_displayCombo->itemData(
            m_displayCombo->currentIndex()).toInt();
      if (targetUnits == PlotCurve::Band) {
        labels.push_back(band);
      }
      else if (targetUnits == PlotCurve::Wavelength) {
        if (pvl.findObject("IsisCube").hasGroup("BandBin")) {
          PvlGroup &bandBin = pvl.findObject("IsisCube").findGroup("BandBin");
          if (bandBin.hasKeyword("Center")) {
            PvlKeyword &wavelength = bandBin.findKeyword("Center");
            if (wavelength.size() > (band - 1)) {
              labels.push_back(toDouble(wavelength[band-1]));
            }
          }
        }
      }

      if (stats.Average() == Null) {
        data.push_back(stats);
      }
      else {
        data.push_back(stats);
      }
    }

    delete brick;
  }