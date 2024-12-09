void GLWidget::resizeGL(int width, int height)
    {
        // don't resize in case the render widget is hidden
        if (isHidden())
        {
            return;
        }

        m_parentRenderPlugin->GetRenderUtil()->Validate();

        m_width  = width;
        m_height = height;
        m_gBuffer.Resize(width, height);

        RenderGL::GraphicsManager* graphicsManager = m_parentRenderPlugin->GetGraphicsManager();
        if (graphicsManager == nullptr || m_camera == nullptr)
        {
            return;
        }
    }