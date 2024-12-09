size_t Actor::FindFirstActiveParentBone(size_t skeletalLOD, size_t startNodeIndex) const
    {
        size_t curNodeIndex = startNodeIndex;

        do
        {
            curNodeIndex = m_skeleton->GetNode(curNodeIndex)->GetParentIndex();
            if (curNodeIndex == InvalidIndex)
            {
                return curNodeIndex;
            }

            if (m_skeleton->GetNode(curNodeIndex)->GetSkeletalLODStatus(skeletalLOD))
            {
                return curNodeIndex;
            }
        } while (curNodeIndex != InvalidIndex);

        return InvalidIndex;
    }