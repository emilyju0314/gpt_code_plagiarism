void CBoneSetup::AccumulatePose(
	BoneVector pos[], 
	BoneQuaternion q[], 
	int sequence, 
	float cycle,
	float flWeight,
	float flTime,
	CIKContext *pIKContext
	)
{
	BONE_PROFILE_FUNC(); // ex: x360: up to 3.6ms
#if _DEBUG
	VPROF_INCREMENT_COUNTER("AccumulatePose",1);
#endif

	VPROF( "AccumulatePose" );

	//SNPROF_ANIM( "CBoneSetup::AccumulatePose" );

	// Check alignment.
	if ( cl_use_simd_bones.GetBool() && (!  (reinterpret_cast<uintp>(q) & 0x0F) == 0 ) )
	{
		DebuggerBreakIfDebugging();
		AssertMsg(false,
		"Arguments to AccumulatePose are unaligned. Disaster will result.\n"
		);
	}

	Assert( flWeight >= 0.0f && flWeight <= 1.0f );
	// This shouldn't be necessary, but the Assert should help us catch whoever is screwing this up
	flWeight = clamp( flWeight, 0.0f, 1.0f );

	if ( sequence < 0 || sequence >= m_pStudioHdr->GetNumSeq() )
	{
		AssertMsg( false, "Trying to AccumulatePose with an out-of-range sequence!\n" );
		return;
	}

	// This should help re-use the memory for vectors/quaternions
	// 	BoneVector		pos2[MAXSTUDIOBONES];
	// 	BoneQuaternion	q2[MAXSTUDIOBONES];
	BoneVector *pos2 = g_VectorPool.Alloc();
	BoneQuaternionAligned * q2 = ( BoneQuaternionAligned * ) g_QuaternionPool.Alloc();

	PREFETCH360( pos2, 0 );
	PREFETCH360( q2, 0 );

	// Trigger pose debugger
	if (m_pPoseDebugger)
	{
		m_pPoseDebugger->AccumulatePose( m_pStudioHdr, pIKContext, pos, q, sequence, cycle, m_flPoseParameter, m_boneMask, flWeight, flTime );
	}

	mstudioseqdesc_t	&seqdesc = ((CStudioHdr *)m_pStudioHdr)->pSeqdesc( sequence );

	// add any IK locks to prevent extremities from moving
	CIKContext seq_ik;
	if (seqdesc.numiklocks)
	{
		seq_ik.Init( m_pStudioHdr, vec3_angle, vec3_origin, 0.0, 0, m_boneMask );  // local space relative so absolute position doesn't mater
		seq_ik.AddSequenceLocks( seqdesc, pos, q );
	}

	if ((seqdesc.flags & STUDIO_LOCAL) || (seqdesc.flags & STUDIO_ROOTXFORM) || (seqdesc.flags & STUDIO_WORLD_AND_RELATIVE))
	{
		::InitPose( m_pStudioHdr, pos2, q2, m_boneMask );
	}

	if (CalcPoseSingle( m_pStudioHdr, pos2, q2, seqdesc, sequence, cycle, m_flPoseParameter, m_boneMask, flTime ))
	{

		if ( (seqdesc.flags & STUDIO_ROOTXFORM) && seqdesc.rootDriverIndex > 0 )
		{

			// hack: Remap the driver bone if it's coming in from an included virtual model and the indices might not match
			// poseparam input is ignored for now
			int nRemappedDriverBone = seqdesc.rootDriverIndex;
			virtualmodel_t *pVModel = m_pStudioHdr->GetVirtualModel();
			if (pVModel)
			{
				const virtualgroup_t *pAnimGroup;
				const studiohdr_t *pAnimStudioHdr;
				int baseanimation = m_pStudioHdr->iRelativeAnim( sequence, 0 );
				pAnimGroup = pVModel->pAnimGroup( baseanimation );
				pAnimStudioHdr = ((CStudioHdr *)m_pStudioHdr)->pAnimStudioHdr( baseanimation );
				nRemappedDriverBone = pAnimGroup->masterBone[nRemappedDriverBone];
			}

			matrix3x4a_t rootDriverXform;
			AngleMatrix( RadianEuler(q2[nRemappedDriverBone]), pos2[nRemappedDriverBone], rootDriverXform );

			matrix3x4a_t rootToMove;
			AngleMatrix( RadianEuler(q[0]), pos[0], rootToMove );

			matrix3x4a_t rootMoved;
			ConcatTransforms_Aligned( rootDriverXform, rootToMove, rootMoved );

			MatrixAngles( rootMoved, q2[0], pos2[0] );
		}

		// this weight is wrong, the IK rules won't composite at the correct intensity
		AddLocalLayers( pos2, q2, seqdesc, sequence, cycle, 1.0, flTime, pIKContext );
		SlerpBones( m_pStudioHdr, q, pos, seqdesc, sequence, q2, pos2, flWeight, m_boneMask );
	}

	g_VectorPool.Free( pos2 );
	g_QuaternionPool.Free( q2 );

	if ( pIKContext )
	{
		pIKContext->AddDependencies( seqdesc, sequence, cycle, m_flPoseParameter, flWeight );
	}

	AddSequenceLayers( pos, q, seqdesc, sequence, cycle, flWeight, flTime, pIKContext );

	if (seqdesc.numiklocks)
	{
		seq_ik.SolveSequenceLocks( seqdesc, pos, q );
	}
}