RubberBandTool::RubberBandTool(QWidget *parent) : Tool(parent) {
    p_mouseLoc = NULL;
    p_vertices = NULL;

    p_mouseLoc = new QPoint;
    p_vertices = new QList< QPoint >;
    p_bandingMode = LineMode;

    activate(false);
    repaint();
  }