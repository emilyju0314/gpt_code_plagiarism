void SingleThreadScheduler::RecursiveExecuteActorInstance(ActorInstance* actorInstance, float timePassedInSeconds)
    {
        actorInstance->SetThreadIndex(0);

        m_numUpdated.Increment();

        const bool isVisible = actorInstance->GetIsVisible();

        // check if we want to sample motions
        bool sampleMotions = false;
        actorInstance->SetMotionSamplingTimer(actorInstance->GetMotionSamplingTimer() + timePassedInSeconds);
        if (actorInstance->GetMotionSamplingTimer() >= actorInstance->GetMotionSamplingRate())
        {
            sampleMotions = true;
            actorInstance->SetMotionSamplingTimer(0.0f);

            if (isVisible)
            {
                m_numSampled.Increment();
            }
        }

        if (isVisible)
        {
            m_numVisible.Increment();
        }

        // update the transformations
        actorInstance->UpdateTransformations(timePassedInSeconds, isVisible, sampleMotions);

        // recursively process the attachments
        const size_t numAttachments = actorInstance->GetNumAttachments();
        for (size_t i = 0; i < numAttachments; ++i)
        {
            ActorInstance* attachment = actorInstance->GetAttachment(i)->GetAttachmentActorInstance();
            if (attachment && attachment->GetIsEnabled())
            {
                RecursiveExecuteActorInstance(attachment, timePassedInSeconds);
            }
        }
    }