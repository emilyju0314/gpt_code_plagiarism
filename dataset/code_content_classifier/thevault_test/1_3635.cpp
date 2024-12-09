void CBoneSetup::CalcAutoplaySequences(
	BoneVector pos[], 
	BoneQuaternion q[], 
	float flRealTime,
	CIKContext *pIKContext
	)
{
	BONE_PROFILE_FUNC();
//	ASSERT_NO_REENTRY();

	SNPROF_ANIM( "CBoneSetup::CalcAutoplaySequences" );
	
	int			i;
	if ( pIKContext )
	{
		pIKContext->AddAutoplayLocks( pos, q );
	}

	unsigned short *pList = NULL;
	int count = m_pStudioHdr->GetAutoplayList( &pList );
	for (i = 0; i < count; i++)
	{
		int sequenceIndex = pList[i];
		mstudioseqdesc_t &seqdesc = ((CStudioHdr *)m_pStudioHdr)->pSeqdesc( sequenceIndex );
		if (seqdesc.flags & STUDIO_AUTOPLAY)
		{
			float cycle = 0;
			float cps = Studio_CPS( m_pStudioHdr, seqdesc, sequenceIndex, m_flPoseParameter );
			cycle = flRealTime * cps;
			cycle = cycle - (int)cycle;

			AccumulatePose( pos, q, sequenceIndex, cycle, 1.0, flRealTime, pIKContext );
		}
	}

	if ( pIKContext )
	{
		pIKContext->SolveAutoplayLocks( pos, q );
	}
}