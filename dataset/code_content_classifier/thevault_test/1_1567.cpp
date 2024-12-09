void PlotWindow::createWidgets(MenuOptions optionsToProvide) {
    /*Create plot*/
    m_plot = new QwtPlot();
    m_plot->installEventFilter(this);
    m_plot->setAxisMaxMinor(QwtPlot::yLeft, 5);
    m_plot->setAxisMaxMajor(QwtPlot::xBottom, 30);
    m_plot->setAxisMaxMinor(QwtPlot::xBottom, 5);
    m_plot->setAxisLabelRotation(QwtPlot::xBottom, 45);
    m_plot->setAxisLabelAlignment(QwtPlot::xBottom, Qt::AlignRight);

    /*Plot Legend*/
    m_legend = new QwtLegend();
    m_legend->setDefaultItemMode(QwtLegendData::Clickable);
    m_legend->setWhatsThis("Right Click on a legend item to display the context "
                         "menu.");
    m_plot->insertLegend(m_legend, QwtPlot::RightLegend, 1.0);
    m_legend->installEventFilter(this);

    /*Plot Grid*/
    m_grid = new QwtPlotGrid;
    m_grid->enableXMin(true);
    m_grid->setMajorPen(QPen(Qt::white, 1, Qt::DotLine));
    m_grid->setMinorPen(QPen(Qt::gray, 1, Qt::DotLine));
    m_grid->attach(m_plot);
    m_grid->setVisible(false);

    /*Plot Zoomer*/
    m_zoomer = new QwtPlotZoomer(m_plot->canvas());
    m_zoomer->setRubberBandPen(QPen(Qt::lightGray));
    m_zoomer->setTrackerPen(QPen(Qt::lightGray));

    setCentralWidget(m_plot);
    setupDefaultMenu(optionsToProvide);
  }