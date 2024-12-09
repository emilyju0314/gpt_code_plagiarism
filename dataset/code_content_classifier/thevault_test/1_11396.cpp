float CNPC_ShadowWalker::GetSequenceGroundSpeed(CStudioHdr *pStudioHdr, int iSequence)
{
	float t = SequenceDuration(pStudioHdr, iSequence);

	if (t > 0)
	{
		return (GetSequenceMoveDist(pStudioHdr, iSequence) * m_flSpeedModifier / t);
	}
	else
	{
		return 0;
	}
}