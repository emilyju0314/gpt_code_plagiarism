void CBoneSetup::AddLocalLayers(
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
	BONE_PROFILE_FUNC();
	SNPROF_ANIM("CBoneSetup::AddLocalLayers");

	if (!(seqdesc.flags & STUDIO_LOCAL))
	{
		return;
	}

	for (int i = 0; i < seqdesc.numautolayers; i++)
	{
		mstudioautolayer_t *pLayer = seqdesc.pAutolayer( i );

		if (!(pLayer->flags & STUDIO_AL_LOCAL))
			continue;

		float layerCycle = cycle;
		float layerWeight = flWeight;

		if (pLayer->start != pLayer->end)
		{
			float s = 1.0;

			if (cycle < pLayer->start)
				continue;
			if (cycle >= pLayer->end)
				continue;

			if (cycle < pLayer->peak && pLayer->start != pLayer->peak)
			{
				s = (cycle - pLayer->start) / (pLayer->peak - pLayer->start);
			}
			else if (cycle > pLayer->tail && pLayer->end != pLayer->tail)
			{
				s = (pLayer->end - cycle) / (pLayer->end - pLayer->tail);
			}

			if (pLayer->flags & STUDIO_AL_SPLINE)
			{
				s = SimpleSpline( s );
			}

			if ((pLayer->flags & STUDIO_AL_XFADE) && (cycle > pLayer->tail))
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

			layerCycle = (cycle - pLayer->start) / (pLayer->end - pLayer->start);
		}

		int iSequence = m_pStudioHdr->iRelativeSeq( sequence, pLayer->iSequence );
		AccumulatePose( pos, q, iSequence, layerCycle, layerWeight, flTime, pIKContext );
	}
}