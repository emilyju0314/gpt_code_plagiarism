ScatterPlotWindow::ScatterPlotWindow(QString title,
      Cube *xAxisCube, int xAxisBand, int xAxisBinCount,
      Cube *yAxisCube, int yAxisBand, int yAxisBinCount,
      QwtInterval sampleRange, QwtInterval lineRange,
      QWidget *parent) :
      PlotWindow("Scatter Plot", PlotCurve::CubeDN, PlotCurve::CubeDN, parent,
                 (MenuOptions)(
                   AllMenuOptions &
                     ~BackgroundSwitchMenuOption &
                     ~ShowTableMenuOption &
                     ~ClearPlotMenuOption &
                     ~ShowHideMarkersMenuOption &
                     ~ShowHideCurvesMenuOption &
                     ~ConfigurePlotMenuOption)) {
    m_xAxisCube = xAxisCube;
    m_yAxisCube = yAxisCube;
    m_xAxisCubeBand = xAxisBand;
    m_yAxisCubeBand = yAxisBand;

    m_sampleRange = sampleRange;
    m_lineRange = lineRange;

    m_xCubeDnAlarmRange.first = Null;
    m_xCubeDnAlarmRange.second = Null;
    m_yCubeDnAlarmRange.first = Null;
    m_yCubeDnAlarmRange.second = Null;

    ScatterPlotData *data = new ScatterPlotData(
        xAxisCube, xAxisBand, xAxisBinCount,
        yAxisCube, yAxisBand, yAxisBinCount,
        sampleRange, lineRange);

    m_spectrogram = new QwtPlotSpectrogram;

    m_spectrogram->setData(data);
    m_spectrogram->setTitle("Scatter Plot Counts");
    m_spectrogram->attach(plot());

    disableAxisAutoScale();
    zoomer()->zoom(0);
    plot()->setAxisScale(QwtPlot::xBottom, data->xCubeMin(), data->xCubeMax());
    plot()->setAxisScale(QwtPlot::yLeft, data->yCubeMin(), data->yCubeMax());
    zoomer()->setZoomBase();
    replot();

    QwtScaleWidget *rightAxis = plot()->axisWidget(QwtPlot::yRight);
    rightAxis->setTitle("Counts");
    rightAxis->setColorBarEnabled(true);
//    rightAxis->setColorMap(m_spectrogram->data()->interval(Qt::ZAxis),
//                           m_spectrogram->colorMap());

    plot()->setAxisScale(QwtPlot::yRight,
                         m_spectrogram->data()->interval(Qt::ZAxis).minValue(),
                         m_spectrogram->data()->interval(Qt::ZAxis).maxValue());
    plot()->enableAxis(QwtPlot::yRight);

    plot()->setAxisTitle(QwtPlot::xBottom,
        QFileInfo(xAxisCube->fileName()).baseName() + " Band " +
        QString::number(xAxisBand) + " " +
        plot()->axisTitle(QwtPlot::xBottom).text());
    plot()->setAxisTitle(QwtPlot::yLeft,
        QFileInfo(yAxisCube->fileName()).baseName() + " Band " +
        QString::number(yAxisBand) + " " +
        plot()->axisTitle(QwtPlot::yLeft).text());

    QList<double> contourLevels;
    QwtInterval range = m_spectrogram->data()->interval(Qt::ZAxis);

    for (double level = range.minValue();
         level < range.maxValue();
         level += ((range.maxValue() - range.minValue()) / 6.0)) {
      contourLevels += level;
    }

    m_spectrogram->setContourLevels(contourLevels);

    m_colorize = new QAction(this);
    m_colorize->setText("Colorize");
    m_colorize->setIcon(QPixmap(FileName("$ISISROOT/appdata/images/icons/rgb.png").expanded()));
    connect(m_colorize, SIGNAL(triggered()),
            this, SLOT(colorPlot()));

    m_contour = new QAction(this);
    m_contour->setText("Hide Contour Lines");
    m_contour->setIcon(
        QPixmap(FileName("$ISISROOT/appdata/images/icons/scatterplotcontour.png").expanded()));
    connect(m_contour, SIGNAL(triggered()),
            this, SLOT(showHideContour()));

    QAction *configureAlarmingAct = new QAction(this);
    configureAlarmingAct->setText("Change Alarming");
    configureAlarmingAct->setIcon(
        QPixmap(FileName("$ISISROOT/appdata/images/icons/scatterplotalarming.png").expanded()));
    connect(configureAlarmingAct, SIGNAL(triggered()),
            this, SLOT(configureAlarming()));

    foreach (QAction *menuAction, menuBar()->actions()) {
      if (menuAction->text() == "&Options") {
        QMenu *optsMenu = qobject_cast<QMenu *>(menuAction->parentWidget());
        optsMenu->addAction(m_colorize);
        optsMenu->addAction(m_contour);
        optsMenu->addAction(configureAlarmingAct);
      }
    }

    colorPlot();
    showHideContour();

    plot()->canvas()->installEventFilter(this);
    plot()->canvas()->setMouseTracking(true);

    replot();

    QString instanceName = windowTitle();
    FileName config("$HOME/.Isis/qview/" + instanceName + ".config");
    QSettings settings(config.expanded(),
                       QSettings::NativeFormat);
    m_alarmPlot = settings.value("alarmOntoPlot", true).toBool();
    m_alarmViewport = settings.value("alarmOntoViewport", true).toBool();

    m_alarmPlotSamples = settings.value("alarmPlotSamples", 25).toInt();
    m_alarmPlotLines = settings.value("alarmPlotLines", 25).toInt();

    m_alarmViewportUnits = (AlarmRangeUnits)settings.value("alarmViewportUnits",
                                                           ScreenUnits).toInt();

    m_alarmViewportScreenWidth =
        settings.value("alarmViewportScreenWidth", 5).toInt();
    m_alarmViewportScreenHeight =
        settings.value("alarmViewportScreenHeight", 5).toInt();

    m_alarmViewportXDnBoxSize =
        settings.value("alarmViewportXDnBoxSize", 1.0).toDouble();
    m_alarmViewportYDnBoxSize =
        settings.value("alarmViewportYDnBoxSize", 1.0).toDouble();
  }