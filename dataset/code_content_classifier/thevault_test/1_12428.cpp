bool MotionQueue::ShouldPlayNextMotion()
    {
        // find the first non mixing motion
        MotionInstance* motionInst = m_motionSystem->FindFirstNonMixingMotionInstance();

        // if there isn't a non mixing motion
        if (motionInst == nullptr)
        {
            return false;
        }

        // the total amount of blending time
        const float timeToRemoveFromMaxTime = GetFirstEntry().m_playInfo.m_blendInTime + motionInst->GetFadeTime();

        // if the motion has ended or is stopping, then we should start the next motion
        if (motionInst->GetIsStopping() || motionInst->GetHasEnded())
        {
            return true;
        }
        else
        {
            // if the max playback time is used
            if (motionInst->GetMaxPlayTime() > 0.0f)
            {
                // if the start of the next motion will have completely faded in, before this motion instance will fade out
                if (motionInst->GetCurrentTime() >= motionInst->GetMaxPlayTime() - timeToRemoveFromMaxTime)
                {
                    return true;
                }
            }

            // if we are not looping forever
            if (motionInst->GetMaxLoops() != EMFX_LOOPFOREVER)
            {
                // if we are in our last loop
                if (motionInst->GetMaxLoops() - 1 == motionInst->GetNumCurrentLoops())
                {
                    // if the start of the next motion will have completely faded in, before this motion instance will fade out
                    if (motionInst->GetCurrentTime() >= motionInst->GetDuration() - timeToRemoveFromMaxTime)
                    {
                        return true;
                    }
                }
            }
        }

        // shouldn't play the next motion yet
        return false;
    }