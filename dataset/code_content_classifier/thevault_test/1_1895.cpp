bool CFrameBufferObject::create( GLuint width, GLuint height, fboConfig &config, fboData &data) 
{
    bool multisample = config.depthSamples > 0;
    bool csaa = config.coverageSamples > config.depthSamples;
    bool ret = true;
    GLint query;

	printf("\nCreating FBO <%s> Float:%s\n", config.name.c_str(), (m_bUseFloat ? "Y":"N") );

    glGenFramebuffersEXT(1, &data.fb);
    glGenTextures(1, &data.colorTex);

    // init texture
    glBindTexture( m_eGLTarget, data.colorTex);
    glTexImage2D ( m_eGLTarget, 0, config.colorFormat, 
					width, height, 0, GL_RGBA, 
				   (m_bUseFloat ? GL_FLOAT : GL_UNSIGNED_BYTE), 
					NULL 
				  );

    glGenerateMipmapEXT( m_eGLTarget );
    
    glTexParameterf( m_eGLTarget, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf( m_eGLTarget, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameterf( m_eGLTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf( m_eGLTarget, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // GL_LINEAR);

    //
    // Handle multisample FBO's first
    //
    if (multisample) {
        if (csaa) {
			ret &= createCSAA(width, height, &config, &data);
        }
        else {
			ret &= createMSAA(width, height, &config, &data);
        }
       
        // attach the depth buffer
        glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, data.depthRB);
        ret &= checkStatus(__FILE__, __LINE__, true);
    } 
    else // case if not multisampled
	{ 
        glGenTextures( 1, &data.depthTex );
        data.depthRB = 0;
        data.colorRB = 0;
        data.resolveFB = 0;

        //non-multisample, so bind things directly to the FBO
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, data.fb); 
        glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, m_eGLTarget, data.colorTex, 0);

        glBindTexture(	m_eGLTarget, data.depthTex );
        glTexImage2D(	m_eGLTarget, 0, config.depthFormat, 
						width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    
        glTexParameterf( m_eGLTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // GL_LINEAR);
        glTexParameterf( m_eGLTarget, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // GL_LINEAR);
        glTexParameterf( m_eGLTarget, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf( m_eGLTarget, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameterf( m_eGLTarget, GL_DEPTH_TEXTURE_MODE, GL_LUMINANCE);

        glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, m_eGLTarget, data.depthTex, 0);

        ret &= checkStatus(__FILE__, __LINE__, true);
    }
    
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, data.fb);
    glGetIntegerv( GL_RED_BITS, &query);
    if ( query != config.redbits) {
        ret = false;
    }

    glGetIntegerv( GL_DEPTH_BITS, &query);
    if ( query != config.depthBits) {
        ret = false;
    }

    if (multisample) {
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, data.resolveFB);
        glGetIntegerv( GL_RED_BITS, &query);
        if ( query != config.redbits) {
            ret = false;
        }
    }
    
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

    ret &= checkStatus(__FILE__, __LINE__, true);

    return ret;
}