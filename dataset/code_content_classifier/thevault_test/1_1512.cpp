void ScatterPlotWindow::paint(MdiCubeViewport *vp, QPainter *painter) {
    PlotWindow::paint(vp, painter);

    // Do alarming from plot onto viewport
    if (alarmingViewport() &&
        !IsSpecial(m_xCubeDnAlarmRange.first) &&
        !IsSpecial(m_xCubeDnAlarmRange.second) &&
        !IsSpecial(m_yCubeDnAlarmRange.first) &&
        !IsSpecial(m_yCubeDnAlarmRange.second)) {
      painter->setPen(QPen(Qt::red));

      ViewportBuffer *buffer = vp->grayBuffer();

      if ((isXCube(vp) || isYCube(vp)) && buffer && !buffer->working()) {
        int numLines = buffer->bufferXYRect().height();

        QScopedPointer<Portal> portal;

        // We are going to read DNs from the cube that isn't in the passed in
        //   viewport. For example, if we're painting X, we're missing the
        //   corresponding Y DN values.
        if (isXCube(vp))
          portal.reset(new Portal(1, 1, m_yAxisCube->pixelType()));
        else
          portal.reset(new Portal(1, 1, m_xAxisCube->pixelType()));

        // Iterate through the in-memory DN values for the passed in viewport
        for (int yIndex = 0; yIndex < numLines; yIndex++) {
          const vector<double> &line = buffer->getLine(yIndex);

          for (int xIndex = 0; xIndex < (int)line.size(); xIndex++) {
            int viewportPointX = xIndex + buffer->bufferXYRect().left();
            int viewportPointY = yIndex + buffer->bufferXYRect().top();

            double cubeSample = Null;
            double cubeLine = Null;
            vp->viewportToCube(viewportPointX, viewportPointY,
                               cubeSample, cubeLine);

            // The sample/line range is the actual scatter plotted sample/line
            //   range. Don't alarm outside of this range on the cube ever.
            if (cubeSample >= m_sampleRange.minValue() - 0.5 &&
                cubeSample <= m_sampleRange.maxValue() + 0.5 &&
                cubeLine >= m_lineRange.minValue() - 0.5 &&
                cubeLine <= m_lineRange.maxValue() + 0.5) {
              // If the in-memory DN values are within the alarm box range, check
              //   the corresponding DN values for the other axis via cube I/O.
              if (isXCube(vp) &&
                  line[xIndex] >= m_xCubeDnAlarmRange.first &&
                  line[xIndex] <= m_xCubeDnAlarmRange.second) {
                portal->SetPosition(cubeSample, cubeLine, m_yAxisCubeBand);
                m_yAxisCube->read(*portal);

                double yDnValue = (*portal)[0];

                if (yDnValue >= m_yCubeDnAlarmRange.first &&
                    yDnValue <= m_yCubeDnAlarmRange.second) {
                  painter->drawPoint(viewportPointX, viewportPointY);
                }
              }
              else if (isYCube(vp) &&
                       line[xIndex] >= m_yCubeDnAlarmRange.first &&
                       line[xIndex] <= m_yCubeDnAlarmRange.second) {
                portal->SetPosition(cubeSample, cubeLine, m_xAxisCubeBand);
                m_xAxisCube->read(*portal);

                double xDnValue = (*portal)[0];

                if (xDnValue >= m_xCubeDnAlarmRange.first &&
                    xDnValue <= m_xCubeDnAlarmRange.second) {
                  painter->drawPoint(viewportPointX, viewportPointY);
                }
              }
            }
          }
        }
      }
    }
  }