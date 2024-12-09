void CvCapture_Android::prepareCacheForYUV420i(int width, int height)
{
    if (width != m_width || height != m_height)
    {
	LOGD("CvCapture_Android::prepareCacheForYUV420i: Changing size of buffers: from width=%d height=%d to width=%d height=%d", m_width, m_height, width, height);
        m_width = width;
        m_height = height;
        unsigned char *tmp = m_frameYUV420inext;
        m_frameYUV420inext = new unsigned char [width * height * 3 / 2];
	if (tmp != NULL) {
		delete[] tmp;
	}

        tmp = m_frameYUV420i;
        m_frameYUV420i = new unsigned char [width * height * 3 / 2];
	if (tmp != NULL) {
		delete[] tmp;
	}
    }
}