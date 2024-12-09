void SmokeRenderer::compositeResult()
{
    glViewport(0, 0, mWindowW, mWindowH);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    displayTexture(m_imageTex);
    glDisable(GL_BLEND);
}