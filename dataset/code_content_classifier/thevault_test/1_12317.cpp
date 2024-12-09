MotionInstance* MotionSystem::PlayMotion(Motion* motion, PlayBackInfo* info)
    {
        // check some things
        if (motion == nullptr)
        {
            return nullptr;
        }

        PlayBackInfo tempInfo;
        if (info == nullptr)
        {
            info = &tempInfo;
        }

        // trigger the OnPlayMotion event
        GetEventManager().OnPlayMotion(motion, info);

        // make sure we always mix when using additive blending
        if (info->m_blendMode == BLENDMODE_ADDITIVE && info->m_mix == false)
        {
            MCORE_ASSERT(false); // this shouldn't happen actually, please make sure you always mix additive motions
            info->m_mix = true;
        }

        // create the motion instance and add the motion info the this actor
        MotionInstance* motionInst = CreateMotionInstance(motion, info);

        // if we want to play it immediately (so if we do NOT want to schedule it for later on)
        if (info->m_playNow)
        {
            // start the motion for real
            StartMotion(motionInst, info);
        }
        else
        {
            // schedule the motion, by adding it to the back of the motion queue
            m_motionQueue->AddEntry(MotionQueue::QueueEntry(motionInst, info));
            motionInst->Pause();
            motionInst->SetIsActive(false);
            GetEventManager().OnQueueMotionInstance(motionInst, info);
        }

        // return the pointer to the motion info
        return motionInst;
    }