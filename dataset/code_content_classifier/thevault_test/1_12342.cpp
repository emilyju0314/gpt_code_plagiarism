void AnimGraphTimeCondition::Update(AnimGraphInstance* animGraphInstance, float timePassedInSeconds)
    {
        // add the unique data for the condition to the anim graph
        UniqueData* uniqueData = static_cast<UniqueData*>(animGraphInstance->FindOrCreateUniqueObjectData(this));

        // increase the elapsed time of the condition
        uniqueData->m_elapsedTime += timePassedInSeconds;
    }