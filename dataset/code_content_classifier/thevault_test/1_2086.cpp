void SmokeRenderer::drawSliceLightView(int i)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadMatrixf((GLfloat *) m_lightView.get_value());

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadMatrixf((GLfloat *) m_lightProj.get_value());

    m_lightFbo->Bind();
    glViewport(0, 0, m_lightBufferSize, m_lightBufferSize);

    glColor4f(m_colorAttenuation[0] * m_shadowAlpha, m_colorAttenuation[1] * m_shadowAlpha, m_colorAttenuation[2] * m_shadowAlpha, 1.0);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);

    drawPointSprites(m_particleProg, i*m_batchSize, m_batchSize, false);

    m_lightFbo->Disable();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}