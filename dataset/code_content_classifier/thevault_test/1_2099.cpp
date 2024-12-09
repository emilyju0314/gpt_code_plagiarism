CFrameBufferObject::CFrameBufferObject(unsigned int width, unsigned int height, 
                                       unsigned int Bpp, bool bUseFloat, GLenum eTarget) :
                        m_Width(width),
                        m_Height(height),
			m_bUseFloat(bUseFloat), 
			m_eGLTarget(eTarget)
{
    // reserved for future usage
    if (Bpp) {

    }
#if NEW_FBO_CODE
    glGenFramebuffersEXT(1, &m_fboData.fb);

    m_fboData.colorTex = createTexture(m_eGLTarget, width, height, 
                                (bUseFloat ? GL_RGBA32F_ARB : GL_RGBA8), GL_RGBA);

    m_fboData.depthTex = createTexture( m_eGLTarget, width, height, 
                                        GL_DEPTH_COMPONENT24, GL_DEPTH_COMPONENT);

    attachTexture( m_eGLTarget, m_fboData.colorTex,   GL_COLOR_ATTACHMENT0_EXT );
    attachTexture( m_eGLTarget, m_fboData.depthTex,   GL_DEPTH_ATTACHMENT_EXT  );

//    bool ret = checkStatus(__FILE__, __LINE__, true);
#else
    // this is th eoriginal FBO path
    initialize(width, height, m_fboConfig, m_fboData);
    CHECK_FBO;
#endif
}