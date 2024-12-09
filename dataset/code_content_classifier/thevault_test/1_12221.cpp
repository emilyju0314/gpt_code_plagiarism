Recorder::NodeHistoryItem* Recorder::FindNodeHistoryItem(const ActorInstanceData& actorInstanceData, const AnimGraphNode* node, float recordTime) const
    {
        const AZStd::vector<NodeHistoryItem*>& historyItems = actorInstanceData.m_nodeHistoryItems;
        for (NodeHistoryItem* curItem : historyItems)
        {
            if (curItem->m_nodeId == node->GetId() && curItem->m_startTime <= recordTime && curItem->m_isFinalized == false)
            {
                return curItem;
            }

            if (curItem->m_nodeId == node->GetId() && curItem->m_startTime <= recordTime && curItem->m_endTime >= recordTime && curItem->m_isFinalized)
            {
                return curItem;
            }
        }

        return nullptr;
    }