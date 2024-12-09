bool Recorder::SaveUniqueData(AnimGraphInstance* animGraphInstance, AnimGraphObject* object, AnimGraphInstanceData& animGraphInstanceData)
    {
        // get the current frame's data pointer
        AnimGraphAnimFrame& currentFrame = animGraphInstanceData.m_frames.back();
        const size_t frameOffset = currentFrame.m_byteOffset;

        // prepare the objects array
        m_objects.clear();
        m_objects.reserve(1024);

        // collect the objects we are going to save for this frame
        object->RecursiveCollectObjects(m_objects);

        // resize the object infos array
        const size_t numObjects = m_objects.size();
        currentFrame.m_objectInfos.resize(numObjects);

        // calculate how much memory we need for this frame
        size_t requiredFrameBytes = 0;
        for (const AnimGraphObject* animGraphObject : m_objects)
        {
            requiredFrameBytes += animGraphObject->SaveUniqueData(animGraphInstance, nullptr);
        }

        // make sure we have at least the given amount of space in the buffer we are going to write the frame data to
        if (!AssureAnimGraphBufferSize(animGraphInstanceData, requiredFrameBytes + currentFrame.m_byteOffset))
        {
            return false;
        }
        uint8* dataPointer = &animGraphInstanceData.m_dataBuffer[frameOffset];

        // save all the unique datas for the objects
        for (size_t i = 0; i < numObjects; ++i)
        {
            // store the object info
            AnimGraphObject* curObject = m_objects[i];
            currentFrame.m_objectInfos[i].m_object = curObject;
            currentFrame.m_objectInfos[i].m_frameByteOffset = currentFrame.m_numBytes;

            // write the unique data
            const size_t numBytesWritten = curObject->SaveUniqueData(animGraphInstance, dataPointer);

            // increase some offsets/pointers
            currentFrame.m_numBytes += numBytesWritten;
            dataPointer += numBytesWritten;
        }

        // make sure we have a match here, otherwise some of the object->SaveUniqueData(dataPointer) returns different values than object->SaveUniqueData(nullptr)
        MCORE_ASSERT(requiredFrameBytes == currentFrame.m_numBytes);

        return true;
    }