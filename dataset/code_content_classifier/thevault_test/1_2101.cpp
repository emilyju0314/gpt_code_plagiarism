void CFrameBufferObject::renderQuad(int width, int height, GLenum eTarget)
{
#if 1
    float width_norm  = (float)width/(float)m_Width,
          height_norm = (float)height/(float)m_Height;

    // Bind the FBO texture for the display path
    glBindTexture(eTarget, m_fboData.colorTex);

    glGenerateMipmapEXT( GL_TEXTURE_2D );
    glBindTexture(eTarget, 0);

    // now render to the full screen using this texture
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, m_textureProgram );
	glEnable(GL_FRAGMENT_PROGRAM_ARB);
	glDisable(GL_DEPTH_TEST);

	glBegin(GL_QUADS);
	{
		glVertex2f(0.0f      , 0.0f       ); glTexCoord2f(0.0f      , 0.0f       );
		glVertex2f(0.0f      , height_norm); glTexCoord2f(width_norm, 0.0f       );
		glVertex2f(width_norm, height_norm); glTexCoord2f(width_norm, height_norm);
		glVertex2f(width_norm, 0.0f       ); glTexCoord2f(0.0f      , height_norm);
	}
	glEnd();

    // Release the FBO texture (finished rendering)
    glBindTexture(eTarget, 0);

#else
    // Bind the FBO texture for the display path
    glBindTexture(eTarget, m_fboData.colorTex);

    // render a screen sized quad
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glEnable(eTarget);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();

    glViewport(0, 0, width, height);

    if (m_bUseFloat) {
       // fragment program is required to display floating point texture
       glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, m_textureProgram );
       glEnable(GL_FRAGMENT_PROGRAM_ARB);
       glDisable(GL_DEPTH_TEST);
    }

    glBegin(GL_QUADS);
    if (eTarget == GL_TEXTURE_2D) {
       glTexCoord2f(0.0f , 0.0f  ); glVertex3f(-1.0f, -1.0f, 0.5f);
       glTexCoord2f(1.0f , 0.0f  ); glVertex3f( 1.0f, -1.0f, 0.5f);
       glTexCoord2f(1.0f , 1.0f  ); glVertex3f( 1.0f,  1.0f, 0.5f);
       glTexCoord2f(0.0f , 1.0f  ); glVertex3f(-1.0f,  1.0f, 0.5f);
    } else {
       glTexCoord2f(0.0f , 0.0f  ); glVertex3f(-1.0f, -1.0f, 0.5f);
       glTexCoord2f(width, 0.0f  ); glVertex3f( 1.0f, -1.0f, 0.5f);
       glTexCoord2f(width, height); glVertex3f( 1.0f,  1.0f, 0.5f);
       glTexCoord2f(0.0f , height); glVertex3f(-1.0f,  1.0f, 0.5f);
    }

    glEnd();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glDisable(eTarget);

    // Release the FBO texture (finished rendering)
    glBindTexture(eTarget, 0);
#endif
}