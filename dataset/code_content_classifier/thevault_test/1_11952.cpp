void CommandPlayMotion::CommandParametersToPlaybackInfo(Command* command, const MCore::CommandLine& parameters, EMotionFX::PlayBackInfo* outPlaybackInfo)
    {
        if (parameters.CheckIfHasParameter("blendInTime") == true)
        {
            outPlaybackInfo->m_blendInTime = parameters.GetValueAsFloat("blendInTime", command);
        }
        if (parameters.CheckIfHasParameter("blendOutTime"))
        {
            outPlaybackInfo->m_blendOutTime = parameters.GetValueAsFloat("blendOutTime", command);
        }
        if (parameters.CheckIfHasParameter("playSpeed"))
        {
            outPlaybackInfo->m_playSpeed = parameters.GetValueAsFloat("playSpeed", command);
        }
        if (parameters.CheckIfHasParameter("targetWeight"))
        {
            outPlaybackInfo->m_targetWeight = parameters.GetValueAsFloat("targetWeight", command);
        }
        if (parameters.CheckIfHasParameter("eventWeightThreshold"))
        {
            outPlaybackInfo->m_eventWeightThreshold = parameters.GetValueAsFloat("eventWeightThreshold", command);
        }
        if (parameters.CheckIfHasParameter("maxPlayTime"))
        {
            outPlaybackInfo->m_maxPlayTime = parameters.GetValueAsFloat("maxPlayTime", command);
        }
        if (parameters.CheckIfHasParameter("numLoops"))
        {
            outPlaybackInfo->m_numLoops = parameters.GetValueAsInt("numLoops", command);
        }
        if (parameters.CheckIfHasParameter("priorityLevel"))
        {
            outPlaybackInfo->m_priorityLevel = parameters.GetValueAsInt("priorityLevel", command);
        }
        if (parameters.CheckIfHasParameter("blendMode"))
        {
            outPlaybackInfo->m_blendMode = (EMotionFX::EMotionBlendMode)parameters.GetValueAsInt("blendMode", command);
        }
        if (parameters.CheckIfHasParameter("playMode"))
        {
            outPlaybackInfo->m_playMode = (EMotionFX::EPlayMode)parameters.GetValueAsInt("playMode", command);
        }
        if (parameters.CheckIfHasParameter("mirrorMotion"))
        {
            outPlaybackInfo->m_mirrorMotion = parameters.GetValueAsBool("mirrorMotion", command);
        }
        if (parameters.CheckIfHasParameter("mix"))
        {
            outPlaybackInfo->m_mix = parameters.GetValueAsBool("mix", command);
        }
        if (parameters.CheckIfHasParameter("playNow"))
        {
            outPlaybackInfo->m_playNow = parameters.GetValueAsBool("playNow", command);
        }
        if (parameters.CheckIfHasParameter("motionExtraction"))
        {
            outPlaybackInfo->m_motionExtractionEnabled = parameters.GetValueAsBool("motionExtraction", command);
        }
        if (parameters.CheckIfHasParameter("retarget"))
        {
            outPlaybackInfo->m_retarget = parameters.GetValueAsBool("retarget", command);
        }
        if (parameters.CheckIfHasParameter("freezeAtLastFrame"))
        {
            outPlaybackInfo->m_freezeAtLastFrame = parameters.GetValueAsBool("freezeAtLastFrame", command);
        }
        if (parameters.CheckIfHasParameter("enableMotionEvents"))
        {
            outPlaybackInfo->m_enableMotionEvents = parameters.GetValueAsBool("enableMotionEvents", command);
        }
        if (parameters.CheckIfHasParameter("blendOutBeforeEnded"))
        {
            outPlaybackInfo->m_blendOutBeforeEnded = parameters.GetValueAsBool("blendOutBeforeEnded", command);
        }
        if (parameters.CheckIfHasParameter("canOverwrite"))
        {
            outPlaybackInfo->m_canOverwrite = parameters.GetValueAsBool("canOverwrite", command);
        }
        if (parameters.CheckIfHasParameter("deleteOnZeroWeight"))
        {
            outPlaybackInfo->m_deleteOnZeroWeight = parameters.GetValueAsBool("deleteOnZeroWeight", command);
        }
        if (parameters.CheckIfHasParameter("inPlace"))
        {
            outPlaybackInfo->m_inPlace = parameters.GetValueAsBool("inPlace", command);
        }
    }