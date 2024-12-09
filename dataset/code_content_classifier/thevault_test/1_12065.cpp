TimeTrackElement* TimeViewPlugin::GetElementAt(int32 x, int32 y)
    {
        // for all tracks
        for (const TimeTrack* track : m_tracks)
        {
            // check if the absolute pixel is inside
            TimeTrackElement* result = track->GetElementAt(aznumeric_cast<int32>(x + m_scrollX), y);
            if (result)
            {
                return result;
            }
        }

        return nullptr;
    }