void display()
{
    cutilCheckError(cutStartTimer(timer));  

    // map PBO to get CUDA device pointer
    uchar4 *d_output;
    //DEPRECATED: cutilSafeCall( cudaGLMapBufferObject((void**)&d_output, pbo) );
    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_pbo_resource, 0));
    size_t num_bytes; 
    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void **)&d_output, &num_bytes,  
						       cuda_pbo_resource));
    render( imageWidth, imageHeight, tx, ty, scale, cx, cy, 
            blockSize, gridSize, mode, d_output );

    // DEPRECATED: cutilSafeCall(cudaGLUnmapBufferObject(pbo));
    cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_pbo_resource, 0));

    // Common diplay path
    {
	// display results
	glClear(GL_COLOR_BUFFER_BIT);
	
#if USE_BUFFER_TEX
	// display using buffer texture
	glBindTexture(GL_TEXTURE_BUFFER_EXT, bufferTex);
	glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, fprog);
	glEnable(GL_FRAGMENT_PROGRAM_ARB);
	glProgramLocalParameterI4iNV(GL_FRAGMENT_PROGRAM_ARB, 0, width, 0, 0, 0);
#else
	// download image from PBO to OpenGL texture
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
	glBindTexture  (GL_TEXTURE_TYPE, displayTex);
	glPixelStorei  (GL_UNPACK_ALIGNMENT, 1);
	glTexSubImage2D(GL_TEXTURE_TYPE,
			0, 0, 0, width, height, GL_BGRA, GL_UNSIGNED_BYTE, 0);
	glEnable(GL_TEXTURE_TYPE);
#endif
	
	// draw textured quad
	glDisable(GL_DEPTH_TEST);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f          , (GLfloat)height);  glVertex2f(0.0f, 0.0f);
	glTexCoord2f((GLfloat)width, (GLfloat)height);  glVertex2f(1.0f, 0.0f);
	glTexCoord2f((GLfloat)width, 0.0f           );  glVertex2f(1.0f, 1.0f);
	glTexCoord2f(0.0f          , 0.0f           );  glVertex2f(0.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_TYPE);
	glDisable(GL_FRAGMENT_PROGRAM_ARB);
	
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);
	
	if (drawCurves) {
	    // draw spline curves
	    glPushMatrix();
	    glScalef(0.25, 0.25, 1.0);
	    
	    glTranslatef(0.0, 2.0, 0.0);
	    glColor3f(1.0, 0.0, 0.0);
	    plotCurve(bspline_w3);
	    
	    glTranslatef(1.0, 0.0, 0.0);
	    glColor3f(0.0, 1.0, 0.0);
	    plotCurve(bspline_w2);
	    
	    glTranslatef(1.0, 0.0, 0.0);
	    glColor3f(0.0, 0.0, 1.0);
	    plotCurve(bspline_w1);
	    
	    glTranslatef(1.0, 0.0, 0.0);
	    glColor3f(1.0, 0.0, 1.0);
	    plotCurve(bspline_w0);
	    
	    glPopMatrix();
	    glColor3f(1.0, 1.0, 1.0);
	}
    }
    
    glutSwapBuffers();
    glutReportErrors();
    
    cutilCheckError(cutStopTimer(timer));  
    
    computeFPS();
}