size_t Recorder::FindFreeEventHistoryItemTrack(const ActorInstanceData& actorInstanceData, EventHistoryItem* item) const
    {
        const AZStd::vector<EventHistoryItem*>& historyItems = actorInstanceData.m_eventHistoryItems;
        bool found = false;
        size_t trackIndex = 0;
        while (found == false)
        {
            bool hasCollision = false;

            for (const EventHistoryItem* curItem : historyItems)
            {
                if (curItem->m_trackIndex != trackIndex)
                {
                    continue;
                }

                if (MCore::Compare<float>::CheckIfIsClose(curItem->m_startTime, item->m_startTime, 0.01f))
                {
                    hasCollision = true;
                    break;
                }
            }

            if (hasCollision)
            {
                trackIndex++;
            }
            else
            {
                found = true;
            }
        }

        return trackIndex;
    }