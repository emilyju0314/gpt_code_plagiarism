void SmokeRenderer::drawSlices()
{
    m_batchSize = mNumParticles / m_numSlices;

    // clear light buffer
    m_srcLightTexture = 0;
    m_lightFbo->Bind();
    m_lightFbo->AttachTexture(GL_TEXTURE_2D, m_lightTexture[m_srcLightTexture], GL_COLOR_ATTACHMENT0_EXT);
	glClearColor(1.0 - m_lightColor[0], 1.0 - m_lightColor[1], 1.0 - m_lightColor[2], 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    m_lightFbo->Disable();

    // clear volume image
    m_imageFbo->Bind();
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glClear(GL_COLOR_BUFFER_BIT);
    m_imageFbo->Disable();

    glActiveTexture(GL_TEXTURE0);
    glMatrixMode(GL_TEXTURE);
    glLoadMatrixf((GLfloat *) m_shadowMatrix.get_value());

    // render slices
	if (m_numDisplayedSlices > m_numSlices) m_numDisplayedSlices = m_numSlices;

    for(int i=0; i<m_numDisplayedSlices; i++) {
        // draw slice from camera view, sampling light buffer
        drawSlice(i);
        // draw slice from light view to light buffer, accumulating shadows
        drawSliceLightView(i);

        if (m_doBlur) {
            blurLightBuffer();
        }
    }

    glActiveTexture(GL_TEXTURE0);
    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
}