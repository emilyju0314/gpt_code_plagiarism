bool Recorder::AssureAnimGraphBufferSize(AnimGraphInstanceData& animGraphInstanceData, size_t numBytes)
    {
        // if the buffer is big enough, do nothing
        if (animGraphInstanceData.m_dataBufferSize >= numBytes)
        {
            return true;
        }

        // we need to reallocate to grow the buffer
        const size_t newNumBytes = animGraphInstanceData.m_dataBufferSize + (numBytes - animGraphInstanceData.m_dataBufferSize) * 100; // allocate 100 frames ahead
        void* newBuffer = MCore::Realloc(animGraphInstanceData.m_dataBuffer, newNumBytes, EMFX_MEMCATEGORY_RECORDER);
        MCORE_ASSERT(newBuffer);
        if (newBuffer)
        {
            animGraphInstanceData.m_dataBuffer = static_cast<uint8*>(newBuffer);
            animGraphInstanceData.m_dataBufferSize = newNumBytes;
            return true;
        }
        RecorderNotificationBus::Broadcast(&RecorderNotificationBus::Events::OnRecordingFailed,
            "There is not enough memory to continue the current EMotionFX "
            "recording. It was deleted to free memory in order to keep the "
            "editor stable."
            );
        return false;
    }