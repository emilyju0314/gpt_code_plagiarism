size_t Recorder::FindAnimGraphDataFrameNumber(float timeValue) const
    {
        // check if we recorded any actor instances at all
        if (m_actorInstanceDatas.empty())
        {
            return 0;
        }

        // just search in the first actor instances data
        const ActorInstanceData& actorInstanceData = *m_actorInstanceDatas[0];
        const AnimGraphInstanceData* animGraphData = actorInstanceData.m_animGraphData;
        if (animGraphData == nullptr)
        {
            return InvalidIndex;
        }

        const size_t numFrames = animGraphData->m_frames.size();
        if (numFrames == 0)
        {
            return InvalidIndex;
        }
        if (numFrames == 1)
        {
            return 0;
        }

        if (timeValue <= 0.0f)
        {
            return 0;
        }

        if (timeValue > animGraphData->m_frames.back().m_timeValue)
        {
            return animGraphData->m_frames.size() - 1;
        }

        for (size_t i = 0; i < numFrames - 1; ++i)
        {
            const AnimGraphAnimFrame& curFrame  = animGraphData->m_frames[i];
            const AnimGraphAnimFrame& nextFrame = animGraphData->m_frames[i + 1];
            if (curFrame.m_timeValue <= timeValue && nextFrame.m_timeValue > timeValue)
            {
                return i;
            }
        }

        return InvalidIndex;
    }