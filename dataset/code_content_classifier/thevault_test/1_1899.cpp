bool CheckFBO::readback( GLuint width, GLuint height, GLuint bufObject )
{
    bool ret = false;

    if (m_bUseFBO) {
        if (m_bUsePBO) 
        {
            printf("CheckFBO::readback() FBO->PBO->m_pImageData\n");
            // binds the PBO for readback
            bindReadback();

            // bind FBO buffer (we want to transfer FBO -> PBO)
            glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, bufObject );

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
            printf("CheckFBO::readback() FBO->m_pImageData\n");
            // Reading direct to FBO using glReadPixels
            glBindFramebufferEXT( GL_FRAMEBUFFER_EXT, bufObject );
            ret = checkStatus(__FILE__, __LINE__, true);
            if (!ret) printf("CheckFBO::readback::glBindFramebufferEXT() fbo=%d checkStatus = %d\n", bufObject, ret);

            glReadBuffer(static_cast<GLenum>(GL_COLOR_ATTACHMENT0_EXT));
            ret &= checkStatus(__FILE__, __LINE__, true);
            if (!ret) printf("CheckFBO::readback::glReadBuffer() fbo=%d checkStatus = %d\n", bufObject, ret);

            glReadPixels(0, 0, width, height, getPixelFormat(), GL_UNSIGNED_BYTE, m_pImageData);

            glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
        }
    } else {
        printf("CheckFBO::readback() PBO->m_pImageData\n");
        // read from bufObject (PBO) to system memorys image
		glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB, bufObject);	// Bind the PBO

        // map - unmap simulates readback without the copy
        void *ioMem = glMapBufferARB(GL_PIXEL_PACK_BUFFER_ARB, GL_READ_ONLY_ARB);
        memcpy(m_pImageData,    ioMem, width*height*m_Bpp);

	    glUnmapBufferARB(GL_PIXEL_PACK_BUFFER_ARB);

        // read from bufObject (PBO) to system memory image
		glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB, 0);	// unBind the PBO
    }
	return CHECK_FBO;
}