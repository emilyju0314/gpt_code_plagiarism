void Tool::setCubeViewport(MdiCubeViewport *cvp) {
    if(cvp == m_cvp) {
      updateTool();
      return;
    }

    if(m_active)
      removeViewportConnections();

    m_cvp = cvp;

    if(m_active) {
      addViewportConnections();
      enableToolBar();
    }
    else {
      updateTool();
    }

    emit viewportChanged();
  }