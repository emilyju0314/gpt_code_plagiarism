foreach (MdiCubeViewport *viewport, viewportsToPlot()) {
        /* We'll need X-Axis labels and a xMax to scale to.*/
        QVector<double> labels;
        Statistics wavelengthStats;

        QVector<QPointF> avgData, minData, maxData, std1Data, std2Data,
            stdErr1Data, stdErr2Data, wavelengthData;
        QVector<Statistics> plotStats;

        getSpectralStatistics(labels, plotStats, viewport);

        for (int index = 0; index < labels.size(); index++) {
          if (!IsSpecial(plotStats[index].Average()) &&
              !IsSpecial(plotStats[index].Minimum()) &&
              !IsSpecial(plotStats[index].Maximum())) {
            avgData.append(QPointF(labels[index], plotStats[index].Average()));
            minData.append(QPointF(labels[index], plotStats[index].Minimum()));
            maxData.append(QPointF(labels[index], plotStats[index].Maximum()));

            if (!IsSpecial(plotStats[index].StandardDeviation())) {
              std1Data.append(QPointF(labels[index],
                  plotStats[index].Average() +
                  plotStats[index].StandardDeviation()));
              std2Data.append(QPointF(labels[index],
                  plotStats[index].Average() -
                  plotStats[index].StandardDeviation()));

              double standardError = plotStats[index].StandardDeviation() /
                                     sqrt(plotStats[index].ValidPixels());

              stdErr1Data.append(QPointF(labels[index],
                                         plotStats[index].Average() +
                                         standardError));
              stdErr2Data.append(QPointF(labels[index],
                                         plotStats[index].Average() -
                                         standardError));
            }
          }
        } /*end for loop*/

        if (labels.size() > 0) {
          QList<QPoint> rubberBandPoints = rubberBandTool()->vertices();

          validatePlotCurves();
          if (m_plotAvgAction->isChecked()) {
            (*m_avgCurves)[viewport]->setData(new QwtPointSeriesData(avgData));
            (*m_avgCurves)[viewport]->setSource(viewport, rubberBandPoints);
          }

          if (m_plotMinAction->isChecked()) {
            (*m_minCurves)[viewport]->setData(new QwtPointSeriesData(minData));
            (*m_minCurves)[viewport]->setSource(viewport, rubberBandPoints);
          }

          if (m_plotMaxAction->isChecked()) {
            (*m_maxCurves)[viewport]->setData(new QwtPointSeriesData(maxData));
            (*m_maxCurves)[viewport]->setSource(viewport, rubberBandPoints);
          }

          if (m_plotStdDev1Action->isChecked()) {
            (*m_stdDev1Curves)[viewport]->setData(
                new QwtPointSeriesData(std1Data));
            (*m_stdDev1Curves)[viewport]->setSource(viewport,
                                                    rubberBandPoints);
          }

          if (m_plotStdDev2Action->isChecked()) {
            (*m_stdDev2Curves)[viewport]->setData(
                new QwtPointSeriesData(std2Data));
            (*m_stdDev2Curves)[viewport]->setSource(viewport,
                                                    rubberBandPoints);
          }

          if (m_plotStdErr1Action->isChecked()) {
            (*m_stdErr1Curves)[viewport]->setData(
                new QwtPointSeriesData(stdErr1Data));
            (*m_stdErr1Curves)[viewport]->setSource(viewport,
                                                    rubberBandPoints);
          }

          if (m_plotStdErr2Action->isChecked()) {
            (*m_stdErr2Curves)[viewport]->setData(
                new QwtPointSeriesData(stdErr2Data));
            (*m_stdErr2Curves)[viewport]->setSource(viewport,
                                                    rubberBandPoints);
          }
        }
      }