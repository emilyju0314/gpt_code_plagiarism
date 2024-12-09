PlotWindow::PlotWindow(QString title, PlotCurve::Units xAxisUnits,
                         PlotCurve::Units yAxisUnits, QWidget *parent,
                         MenuOptions optionsToProvide) :
        MainWindow(title, parent) {

    m_toolBar = NULL;
    m_menubar = NULL;
    m_tableWindow = NULL;
    m_pasteAct = NULL;
    m_allowUserToAddCurves = true;
    m_autoscaleAxes = true;

    setObjectName("Plot Window: " + title);

    m_parent = parent;
    m_xAxisUnits = xAxisUnits;
    m_yAxisUnits = yAxisUnits;

    if (!m_parent) {
      IString msg = "PlotWindow cannot be instantiated with a NULL parent";
      throw IException(IException::Programmer, msg, _FILEINFO_);
    }

    installEventFilter(this);
    setAcceptDrops(true);

    createWidgets(optionsToProvide);
    setWindowTitle(title);

    setPlotBackground(Qt::black);

    connect(QGuiApplication::clipboard(), SIGNAL(changed(QClipboard::Mode)),
            this, SLOT(onClipboardChanged()));
    connect(this, SIGNAL(plotChanged()),
            this, SLOT(scheduleFillTable()));
    connect(this, SIGNAL(requestFillTable()),
            this, SLOT(fillTable()), Qt::QueuedConnection);

    QMap<PlotCurve::Units, QString> unitLabels;
    unitLabels.insert(PlotCurve::Band, "Band");
    unitLabels.insert(PlotCurve::Percentage, "Percentage");
    unitLabels.insert(PlotCurve::PixelNumber, "Pixel Number");
    unitLabels.insert(PlotCurve::CubeDN, "Pixel Value");
    unitLabels.insert(PlotCurve::Elevation, "Elevation");
    unitLabels.insert(PlotCurve::Meters, "Meters");
    unitLabels.insert(PlotCurve::Kilometers, "Kilometers");
    unitLabels.insert(PlotCurve::Wavelength, "Wavelength");

    plot()->setAxisTitle(QwtPlot::xBottom, unitLabels[xAxisUnits]);
    plot()->setAxisTitle(QwtPlot::yLeft,   unitLabels[yAxisUnits]);
    setPlotTitle(title);

    onClipboardChanged();

    readSettings();

#ifdef __APPLE__
    setWindowFlags(Qt::Tool);
#else
    setWindowFlags(Qt::Dialog);
#endif
  }