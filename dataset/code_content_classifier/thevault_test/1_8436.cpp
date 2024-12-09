void CSTrooper :: SpeakSentence( void )
{
	if ( m_iSentence == STROOPER_SENT_NONE )
	{
		// no sentence cued up.
		return; 
	}

	if (FOkToSpeak())
	{
		SENTENCEG_PlayRndSz( ENT(pev), pTrooperSentences[ m_iSentence ], STROOPER_SENTENCE_VOLUME, TROOPER_ATTN, 0, m_voicePitch);
		JustSpoke();
	}
}