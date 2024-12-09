void SmokeRenderer::drawSlice(int i)
{
    m_imageFbo->Bind();
    glViewport(0, 0, m_imageW, m_imageH);

    glColor4f(1.0, 1.0, 1.0, m_spriteAlpha);

    if (m_invertedView) {
        // front-to-back
        glBlendFunc(GL_ONE_MINUS_DST_ALPHA, GL_ONE);
    } else {
        // back-to-front
        glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    }
    drawPointSprites(m_particleShadowProg, i*m_batchSize, m_batchSize, true);

    m_imageFbo->Disable();
}