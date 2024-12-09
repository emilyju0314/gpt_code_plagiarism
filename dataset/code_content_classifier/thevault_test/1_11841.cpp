void CTimeRangeKeyUIControls::OnUIChange(IVariable* pVar, CTrackViewKeyBundle& selectedKeys)
{
    CTrackViewSequence* pSequence = GetIEditor()->GetAnimation()->GetSequence();

    if (!pSequence || !selectedKeys.AreAllKeysOfSameType())
    {
        return;
    }

    for (unsigned int keyIndex = 0, num = (int)selectedKeys.GetKeyCount(); keyIndex < num; keyIndex++)
    {
        CTrackViewKeyHandle keyHandle = selectedKeys.GetKey(keyIndex);

        CAnimParamType paramType = keyHandle.GetTrack()->GetParameterType();
        if (paramType == AnimParamType::TimeRanges)
        {
            ITimeRangeKey timeRangeKey;
            keyHandle.GetKey(&timeRangeKey);

            SyncValue(mv_startTime, timeRangeKey.m_startTime, false, pVar);
            SyncValue(mv_endTime, timeRangeKey.m_endTime, false, pVar);
            SyncValue(mv_timeScale, timeRangeKey.m_speed, false, pVar);
            SyncValue(mv_bLoop, timeRangeKey.m_bLoop, false, pVar);

            // Clamp values
            if (!timeRangeKey.m_bLoop)
            {
                timeRangeKey.m_endTime = std::min(timeRangeKey.m_duration, timeRangeKey.m_endTime);
            }
            timeRangeKey.m_startTime = std::min(timeRangeKey.m_duration, timeRangeKey.m_startTime);
            timeRangeKey.m_startTime = std::min(timeRangeKey.m_endTime, timeRangeKey.m_startTime);

            keyHandle.SetKey(&timeRangeKey);
        }
    }
}