void BlendTreeMorphTargetNode::UpdateMorphIndices(ActorInstance* actorInstance, UniqueData* uniqueData, bool forceUpdate)
    {
        // Check if our LOD level changed, if not, we don't need to refresh it.
        const size_t lodLevel = actorInstance->GetLODLevel();
        if (!forceUpdate && uniqueData->m_lastLodLevel == lodLevel)
        {
            return;
        }

        // Convert the morph target name into an index for fast lookup.
        if (!m_morphTargetNames.empty())
        {
            const EMotionFX::MorphSetup* morphSetup = actorInstance->GetActor()->GetMorphSetup(lodLevel);
            if (morphSetup)
            {
                const AZStd::string& morphTargetName = m_morphTargetNames[0];
                uniqueData->m_morphTargetIndex = morphSetup->FindMorphTargetIndexByName(morphTargetName.c_str());
            }
        }
        else
        {
            uniqueData->m_morphTargetIndex = InvalidIndex;
        }

        uniqueData->m_lastLodLevel = lodLevel;
    }