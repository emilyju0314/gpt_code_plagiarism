bool CheckBackBuffer::readback( GLuint width, GLuint height, unsigned char *memBuf )
{
    // let's flip the image as we copy
    for (unsigned int y = 0; y < height; y++) {
        memcpy( (void *)&(m_pImageData[(height-y)*width*m_Bpp]), (void *)&(memBuf[y*width*m_Bpp]), width*m_Bpp);
    }
	return true;
}