void GLWidget::initializeGL()
    {
        // initializeOpenGLFunctions() and m_parentRenderPlugin->InitializeGraphicsManager must be called first to ensure
        // all OpenGL functions have been resolved before doing anything that could make GL calls (e.g. resizing)
        initializeOpenGLFunctions();
        m_parentRenderPlugin->InitializeGraphicsManager();
        if (m_parentRenderPlugin->GetGraphicsManager())
        {
            m_parentRenderPlugin->GetGraphicsManager()->SetGBuffer(&m_gBuffer);
        }

        // set minimum render view dimensions
        setMinimumHeight(100);
        setMinimumWidth(100);

        m_perfTimer.StampAndGetDeltaTimeInSeconds();
    }