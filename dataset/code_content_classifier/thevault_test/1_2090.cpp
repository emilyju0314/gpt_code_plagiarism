void SmokeRenderer::beginSceneRender(Target target)
{
    if (target == LIGHT_BUFFER) {
        m_lightFbo->Bind();
        glViewport(0, 0, m_lightBufferSize, m_lightBufferSize);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadMatrixf((GLfloat *) m_lightView.get_value());

        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadMatrixf((GLfloat *) m_lightProj.get_value());
    } else {
        m_imageFbo->Bind();
        glViewport(0, 0, m_imageW, m_imageH);
    }
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glDepthMask(GL_TRUE);
    glClear(GL_DEPTH_BUFFER_BIT);
}