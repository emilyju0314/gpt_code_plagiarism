void MotionSystem::AddMotionQueue(MotionQueue* motionQueue)
    {
        MCORE_ASSERT(motionQueue);

        // copy entries from the given queue to the motion system's one
        for (size_t i = 0; i < motionQueue->GetNumEntries(); ++i)
        {
            m_motionQueue->AddEntry(motionQueue->GetEntry(i));
        }

        // get rid of the given motion queue
        motionQueue->Destroy();
    }