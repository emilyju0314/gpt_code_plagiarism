void SmokeRenderer::createBuffers(int w, int h)
{
    if (m_imageFbo) {
        glDeleteTextures(1, &m_imageTex);
        glDeleteTextures(1, &m_depthTex);
        delete m_imageFbo;
    }

    mWindowW = w;
    mWindowH = h;

    m_imageW = w / m_downSample;
    m_imageH = h / m_downSample;

    // create fbo for image buffer
	GLint format = GL_RGBA16F_ARB;
	//GLint format = GL_LUMINANCE16F_ARB;
	//GLint format = GL_RGBA8;
    m_imageTex = createTexture(GL_TEXTURE_2D, m_imageW, m_imageH, format, GL_RGBA);
    m_depthTex = createTexture(GL_TEXTURE_2D, m_imageW, m_imageH, GL_DEPTH_COMPONENT24_ARB, GL_DEPTH_COMPONENT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    m_imageFbo = new FramebufferObject();
    m_imageFbo->AttachTexture(GL_TEXTURE_2D, m_imageTex, GL_COLOR_ATTACHMENT0_EXT);
    m_imageFbo->AttachTexture(GL_TEXTURE_2D, m_depthTex, GL_DEPTH_ATTACHMENT_EXT);
    m_imageFbo->IsValid();
}