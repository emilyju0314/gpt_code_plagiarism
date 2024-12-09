TimeTrack* TimeViewPlugin::GetTrackAt(int32 y)
    {
        // for all tracks
        const auto foundTrack = AZStd::find_if(begin(m_tracks), end(m_tracks), [y](const TimeTrack* track)
        {
            return track->GetIsInside(y);
        });
        return foundTrack != end(m_tracks) ? *foundTrack : nullptr;
    }