void Actor::MatchNodeMotionSourcesGeometrical()
    {
        Pose pose;
        pose.InitFromBindPose(this);

        const uint16 numNodes = static_cast<uint16>(m_skeleton->GetNumNodes());
        for (uint16 i = 0; i < numNodes; ++i)
        {
            // find the best match
            const uint16 bestIndex = FindBestMirrorMatchForNode(i, pose);

            // if a best match has been found
            if (bestIndex != MCORE_INVALIDINDEX16)
            {
                //LogDetailedInfo("%s <---> %s", node->GetName(), GetNode(bestIndex)->GetName());
                MapNodeMotionSource(i, bestIndex);
            }
        }
    }