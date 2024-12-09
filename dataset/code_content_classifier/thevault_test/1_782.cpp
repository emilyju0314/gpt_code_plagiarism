void CvCapture_Android::setFrame(const void* buffer, int bufferSize)
{
    int width = m_activity->getFrameWidth();
    int height = m_activity->getFrameHeight();
    int expectedSize = (width * height * 3) >> 1;

    if ( expectedSize != bufferSize)
    {
        LOGE("ERROR reading YUV420i buffer: width=%d, height=%d, size=%d, receivedSize=%d", width, height, expectedSize, bufferSize);
        return;
    }

    //allocate memory if needed
    prepareCacheForYUV420i(width, height);

    //copy data
    memcpy(m_frameYUV420inext, buffer, bufferSize);
    //LOGD("CvCapture_Android::setFrame -- memcpy is done");

#if 0 //moved this part of code into grabFrame
    //swap current and new frames
    unsigned char* tmp = m_frameYUV420i;
    m_frameYUV420i = m_frameYUV420inext;
    m_frameYUV420inext = tmp;

    //discard cached frames
    m_hasGray = false;
    m_hasColor = false;
#endif

    m_dataState = CVCAPTURE_ANDROID_STATE_HAS_NEW_FRAME_UNGRABBED;
    m_waitingNextFrame = false;//set flag that no more frames required at this moment
}