SpectralPlotTool::SpectralPlotTool(QWidget *parent) :
      AbstractPlotTool(parent),
      m_maxCurves(new QMap< MdiCubeViewport *, QPointer<CubePlotCurve> >),
      m_minCurves(new QMap< MdiCubeViewport *, QPointer<CubePlotCurve> >),
      m_avgCurves(new QMap< MdiCubeViewport *, QPointer<CubePlotCurve> >),
      m_stdDev1Curves(new QMap< MdiCubeViewport *, QPointer<CubePlotCurve> >),
      m_stdDev2Curves(new QMap< MdiCubeViewport *, QPointer<CubePlotCurve> >),
      m_stdErr1Curves(new QMap< MdiCubeViewport *, QPointer<CubePlotCurve> >),
      m_stdErr2Curves(new QMap< MdiCubeViewport *, QPointer<CubePlotCurve> >) {
    connect(this, SIGNAL(viewportChanged()), this, SLOT(viewportSelected()));

    m_displayCombo = new QComboBox;
  }