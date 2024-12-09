void SmokeRenderer::blurLightBuffer()
{
    m_lightFbo->Bind();
    m_lightFbo->AttachTexture(GL_TEXTURE_2D, m_lightTexture[1 - m_srcLightTexture], GL_COLOR_ATTACHMENT0_EXT);
    glViewport(0, 0, m_lightBufferSize, m_lightBufferSize);

    m_blurProg->enable();
    m_blurProg->bindTexture("tex", m_lightTexture[m_srcLightTexture], GL_TEXTURE_2D, 0);
    m_blurProg->setUniform2f("texelSize", 1.0 / (float) m_lightBufferSize, 1.0 / (float) m_lightBufferSize);
    m_blurProg->setUniform1f("blurRadius", m_blurRadius);
    glDisable(GL_DEPTH_TEST);
	drawQuad();
    m_blurProg->disable();

    m_srcLightTexture = 1 - m_srcLightTexture;

    m_lightFbo->Disable();
}