bool TimeViewPlugin::FindResizePoint(int32 x, int32 y, TimeTrackElement** outElement, uint32* outID)
    {
        // for all tracks
        for (const TimeTrack* track : m_tracks)
        {
             if (track->GetIsVisible() == false)
            {
                continue;
            }

            // for all elements
            const size_t numElems = track->GetNumElements();
            for (size_t i = 0; i < numElems; ++i)
            {
                TimeTrackElement* elem = track->GetElement(i);

                // check for a resize point in the element
                uint32 id;
                if (elem->FindResizePoint(x, y, &id))
                {
                    *outElement = elem;
                    *outID = id;
                    return true;
                }
            }
        }

        // no resize point at this location
        *outElement = nullptr;
        *outID      = MCORE_INVALIDINDEX32;

        // no resize point found
        return false;
    }