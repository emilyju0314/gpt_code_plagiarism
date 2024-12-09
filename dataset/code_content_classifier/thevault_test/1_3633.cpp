void CalcPose(
	const CStudioHdr *pStudioHdr,
	CIKContext *pIKContext,
	BoneVector pos[], 
	BoneQuaternionAligned q[], 
	int sequence, 
	float cycle,
	const float poseParameter[],
	int boneMask,
	float flWeight,
	float flTime
	)
{
	BONE_PROFILE_FUNC();
	mstudioseqdesc_t	&seqdesc = pStudioHdr->pSeqdesc( sequence );

	Assert( flWeight >= 0.0f && flWeight <= 1.0f );
	// This shouldn't be necessary, but the Assert should help us catch whoever is screwing this up
	flWeight = clamp( flWeight, 0.0f, 1.0f );

	// add any IK locks to prevent numautolayers from moving extremities 
	CIKContext seq_ik;
	if (seqdesc.numiklocks)
	{
		seq_ik.Init( pStudioHdr, vec3_angle, vec3_origin, 0.0, 0, boneMask ); // local space relative so absolute position doesn't mater
		seq_ik.AddSequenceLocks( seqdesc, pos, q );
	}

	CalcPoseSingle( pStudioHdr, pos, q, seqdesc, sequence, cycle, poseParameter, boneMask, flTime );

	if ( pIKContext )
	{
		pIKContext->AddDependencies( seqdesc, sequence, cycle, poseParameter, flWeight );
	}
	
	AddSequenceLayers( pStudioHdr, pIKContext, pos, q, seqdesc, sequence, cycle, poseParameter, boneMask, flWeight, flTime );

	if (seqdesc.numiklocks)
	{
		seq_ik.SolveSequenceLocks( seqdesc, pos, q );
	}
}