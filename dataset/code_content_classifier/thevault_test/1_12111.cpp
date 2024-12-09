void GraphicsManager::EndRender()
    {
        m_renderUtil->RenderTextPeriods();
        m_renderUtil->RenderTextures();
        ((MCommon::RenderUtil*)m_renderUtil)->Render2DLines();
    }