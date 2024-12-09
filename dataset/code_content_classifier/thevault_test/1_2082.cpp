void SmokeRenderer::drawPoints(int start, int count, bool sort)
{
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, mPosVbo);
    glVertexPointer(4, GL_FLOAT, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);                

    if (mColorVbo) {
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, mColorVbo);
        glColorPointer(4, GL_FLOAT, 0, 0);
        glEnableClientState(GL_COLOR_ARRAY);
    }

    if (mVelVbo) {
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, mVelVbo);
        glClientActiveTexture(GL_TEXTURE0);
        glTexCoordPointer(4, GL_FLOAT, 0, 0);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    }

    if (sort) {
        glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, mIndexBuffer);
        glDrawElements(GL_POINTS, count, GL_UNSIGNED_INT, (void*) (start*sizeof(unsigned int)) );
        glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);
    } else {
        glDrawArrays(GL_POINTS, start, count);
    }

    glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

    glClientActiveTexture(GL_TEXTURE0);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}