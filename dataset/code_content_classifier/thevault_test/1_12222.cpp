size_t Recorder::CalcMaxEventHistoryTrackIndex(const ActorInstanceData& actorInstanceData) const
    {
        size_t result = 0;
        const AZStd::vector<EventHistoryItem*>& historyItems = actorInstanceData.m_eventHistoryItems;
        for (const EventHistoryItem* curItem : historyItems)
        {
            if (curItem->m_trackIndex > result)
            {
                result = curItem->m_trackIndex;
            }
        }

        return result;
    }