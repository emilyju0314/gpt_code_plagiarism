void CCharacterKeyUIControls::OnUIChange(IVariable* pVar, CTrackViewKeyBundle& selectedKeys)
{
    CTrackViewSequence* pSequence = GetIEditor()->GetAnimation()->GetSequence();

    if (!pSequence || !selectedKeys.AreAllKeysOfSameType())
    {
        return;
    }

    for (unsigned int keyIndex = 0, num = (int)selectedKeys.GetKeyCount(); keyIndex < num; keyIndex++)
    {
        CTrackViewKeyHandle keyHandle = selectedKeys.GetKey(keyIndex);
        CTrackViewTrack* pTrack = keyHandle.GetTrack();
        const CAnimParamType paramType = pTrack->GetParameterType();

        if (paramType == AnimParamType::Animation || keyHandle.GetTrack()->GetValueType() == AnimValueType::CharacterAnim)
        {
            ICharacterKey charKey;
            keyHandle.GetKey(&charKey);

            if (mv_animation.GetVar() == pVar)
            {
                charKey.m_animation = ((QString)mv_animation).toUtf8().data();
                // This call is required to make sure that the newly set animation is properly triggered.
                pTrack->GetSequence()->Reset(false);
            }
            SyncValue(mv_loop, charKey.m_bLoop, false, pVar);
            SyncValue(mv_blendGap, charKey.m_bBlendGap, false, pVar);
            SyncValue(mv_inplace, charKey.m_bInPlace, false, pVar);
            SyncValue(mv_startTime, charKey.m_startTime, false, pVar);
            SyncValue(mv_endTime, charKey.m_endTime, false, pVar);
            SyncValue(mv_timeScale, charKey.m_speed, false, pVar);
            keyHandle.SetKey(&charKey);
        }
    }
}