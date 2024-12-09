void CBoneSetup::AddSequenceLayers(
	BoneVector pos[], 
	BoneQuaternion q[], 
	mstudioseqdesc_t &seqdesc,
	int sequence, 
	float cycle,
	float flWeight,
	float flTime,
	CIKContext *pIKContext
	)
{
	BONE_PROFILE_FUNC(); // ex: x360: 1.84ms
	SNPROF_ANIM("CBoneSetup::AddSequenceLayers");

	for (int i = 0; i < seqdesc.numautolayers; i++)
	{
		mstudioautolayer_t *pLayer = seqdesc.pAutolayer( i );

		if (pLayer->flags & STUDIO_AL_LOCAL)
			continue;

		float layerCycle = cycle;
		float layerWeight = flWeight;

		if (pLayer->start != pLayer->end)
		{
			float s = 1.0;
			float index;

			if (!(pLayer->flags & STUDIO_AL_POSE))
			{
				index = cycle;
			}
			else
			{
				int iSequence = m_pStudioHdr->iRelativeSeq( sequence, pLayer->iSequence );
				int iPose = m_pStudioHdr->GetSharedPoseParameter( iSequence, pLayer->iPose );
				if (iPose != -1)
				{
					const mstudioposeparamdesc_t &Pose = ((CStudioHdr *)m_pStudioHdr)->pPoseParameter( iPose );
					index = m_flPoseParameter[ iPose ] * (Pose.end - Pose.start) + Pose.start;
				}
				else
				{
					index = 0;
				}
			}

			if (index < pLayer->start)
				continue;
			if (index >= pLayer->end)
				continue;

			if (index < pLayer->peak && pLayer->start != pLayer->peak)
			{
				s = (index - pLayer->start) / (pLayer->peak - pLayer->start);
			}
			else if (index > pLayer->tail && pLayer->end != pLayer->tail)
			{
				s = (pLayer->end - index) / (pLayer->end - pLayer->tail);
			}

			if (pLayer->flags & STUDIO_AL_SPLINE)
			{
				s = clamp( SimpleSpline( s ), 0, 1 ); // SimpleSpline imprecision can push some float values outside 0..1
			}

			if ((pLayer->flags & STUDIO_AL_XFADE) && (index > pLayer->tail))
			{
				layerWeight = ( s * flWeight ) / ( 1 - flWeight + s * flWeight );
			}
			else if (pLayer->flags & STUDIO_AL_NOBLEND)
			{
				layerWeight = s;
			}
			else
			{
				layerWeight = flWeight * s;
			}

			if (!(pLayer->flags & STUDIO_AL_POSE))
			{
				layerCycle = (cycle - pLayer->start) / (pLayer->end - pLayer->start);
			}
		}
		else if ( pLayer->start == 0 && pLayer->end == 0 && (pLayer->flags & STUDIO_AL_POSE) )
		{
			int iSequence = m_pStudioHdr->iRelativeSeq( sequence, pLayer->iSequence );
			int iPose = m_pStudioHdr->GetSharedPoseParameter( iSequence, pLayer->iPose );
			if (iPose == -1)
				continue;
			
			const mstudioposeparamdesc_t &Pose = ((CStudioHdr *)m_pStudioHdr)->pPoseParameter( iPose );
			float s = m_flPoseParameter[ iPose ] * (Pose.end - Pose.start) + Pose.start;

			Assert( (pLayer->tail - pLayer->peak) != 0 );

			s = clamp( (s - pLayer->peak) / (pLayer->tail - pLayer->peak), 0, 1 );

			if (pLayer->flags & STUDIO_AL_SPLINE)
			{
				s = clamp( SimpleSpline( s ), 0, 1 ); // SimpleSpline imprecision can push some float values outside 0..1
			}

			layerWeight = flWeight * s;			
		}

		int iSequence = m_pStudioHdr->iRelativeSeq( sequence, pLayer->iSequence );
		AccumulatePose( pos, q, iSequence, layerCycle, layerWeight, flTime, pIKContext );
	}
}