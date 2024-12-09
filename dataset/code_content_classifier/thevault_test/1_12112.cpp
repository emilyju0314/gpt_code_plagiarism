bool GraphicsManager::Init(AZ::IO::PathView shaderPath)
    {
        initializeOpenGLFunctions();

        // shaders
        SetShaderPath(shaderPath);

        // texture cache
        if (m_textureCache.Init() == false)
        {
            return false;
        }

        //if (CreateRandomVectorTexture() == false)
        //return false;

        glDepthFunc(GL_LEQUAL);
        glEnable(GL_DEPTH_TEST);

        glClearColor(m_clearColor.m_r, m_clearColor.m_g, m_clearColor.m_b, 1.0f);

        glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

        glDisable(GL_BLEND);

        // initialize utility rendering
        m_renderUtil = new GLRenderUtil(this);
        m_renderUtil->Init();

        // post processing
        if (m_postProcessing)
        {
            if (InitPostProcessing() == false)
            {
                m_postProcessing = false;
            }
        }

        // Get the maximum number of shader constant components.
        // The number of registers is this number divided by 4.
        // We need at least 1024 registers, so 4096 constant components.
        GLint maxConstantComponents = 0;
        glGetIntegerv(GL_MAX_VERTEX_UNIFORM_COMPONENTS, &maxConstantComponents);
        AZ_Printf("EMotionFX", "Max shader constant components = %d (%d registers)\n", maxConstantComponents, maxConstantComponents / 4);
        AZ_Assert(maxConstantComponents >= 4096, "The GPU does not have the minimum required number of shader constants of 4096. It has %d instead.", maxConstantComponents);

        return true;
    }