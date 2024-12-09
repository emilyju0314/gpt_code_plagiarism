bool CheckFBO::readback( GLuint width, GLuint height )
{
    bool ret = false;

    if (m_bUsePBO) {
        // binds the PBO for readback
        bindReadback();

        // bind FBO buffer (we want to transfer FBO -> PBO)
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, m_pFrameBufferObject->getFbo());

        // Now initiate the readback to PBO
	    glReadPixels(0, 0, width, height, getPixelFormat(),      GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
        ret = checkStatus(__FILE__, __LINE__, true);
        if (!ret) printf("CheckFBO::readback() FBO->PBO checkStatus = %d\n", ret);

	    // map - unmap simulates readback without the copy
	    void *ioMem = glMapBufferARB(GL_PIXEL_PACK_BUFFER_ARB, GL_READ_ONLY_ARB);
        memcpy(m_pImageData,    ioMem, width*height*m_Bpp);

		glUnmapBufferARB(GL_PIXEL_PACK_BUFFER_ARB);

        // release the FBO
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0); 

        // release the PBO
        unbindReadback();
    } else {
        // Reading back from FBO using glReadPixels
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, m_pFrameBufferObject->getFbo());
        ret = checkStatus(__FILE__, __LINE__, true);
        if (!ret) printf("CheckFBO::readback::glBindFramebufferEXT() checkStatus = %d\n", ret);

        glReadBuffer(static_cast<GLenum>(GL_COLOR_ATTACHMENT0_EXT));
        ret &= checkStatus(__FILE__, __LINE__, true);
        if (!ret) printf("CheckFBO::readback::glReadBuffer() checkStatus = %d\n", ret);

	    glReadPixels(0, 0, width, height, getPixelFormat(), GL_UNSIGNED_BYTE, m_pImageData);

	    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
    }

    return CHECK_FBO;
}