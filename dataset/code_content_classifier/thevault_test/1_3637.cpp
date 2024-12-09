void DoQuatInterpBone(
	const mstudiobone_t		*pbones,
	int	ibone,
	CBoneAccessor &bonetoworld
	)
{
	BONE_PROFILE_FUNC();
	matrix3x4a_t	bonematrix;
	Vector				control;

	mstudioquatinterpbone_t *pProc = (mstudioquatinterpbone_t *)pbones[ibone].pProcedure( );
	if (pProc && pbones[pProc->control].parent != -1)
	{
		Quaternion	src;
		float		weight[32];
		float		scale = 0.0;
		Quaternion	quat;
		Vector		pos;

		matrix3x4a_t	tmpmatrix;
		matrix3x4a_t	controlmatrix;
		MatrixInvert( bonetoworld.GetBone( pbones[pProc->control].parent), tmpmatrix );
		ConcatTransforms_Aligned( tmpmatrix, bonetoworld.GetBone( pProc->control ), controlmatrix );

		MatrixAngles( controlmatrix, src, pos ); // FIXME: make a version without pos

		int i;
		for (i = 0; i < pProc->numtriggers; i++)
		{
			float dot = fabs( QuaternionDotProduct( pProc->pTrigger( i )->trigger, src ) );
			// FIXME: a fast acos should be acceptable
			dot = clamp( dot, -1, 1 );
			weight[i] = 1 - (2 * acos( dot ) * pProc->pTrigger( i )->inv_tolerance );
			weight[i] = MAX( 0, weight[i] );
			scale += weight[i];
		}

		if (scale <= 0.001)  // EPSILON?
		{
			AngleMatrix( RadianEuler(pProc->pTrigger( 0 )->quat), pProc->pTrigger( 0 )->pos, bonematrix );
			ConcatTransforms ( bonetoworld.GetBone( pbones[ibone].parent ), bonematrix, bonetoworld.GetBoneForWrite( ibone ) );
			return;
		}

		scale = 1.0 / scale;

		quat.Init( 0, 0, 0, 0);
		pos.Init( );

		for (i = 0; i < pProc->numtriggers; i++)
		{
			if (weight[i])
			{
				float s = weight[i] * scale;
				mstudioquatinterpinfo_t *pTrigger = pProc->pTrigger( i );

				QuaternionAlign( pTrigger->quat, quat, quat );

				quat.x = quat.x + s * pTrigger->quat.x;
				quat.y = quat.y + s * pTrigger->quat.y;
				quat.z = quat.z + s * pTrigger->quat.z;
				quat.w = quat.w + s * pTrigger->quat.w;
				pos.x = pos.x + s * pTrigger->pos.x;
				pos.y = pos.y + s * pTrigger->pos.y;
				pos.z = pos.z + s * pTrigger->pos.z;
			}
		}
		Assert( QuaternionNormalize( quat ) != 0);
		QuaternionMatrix( quat, pos, bonematrix );
	}

	ConcatTransforms_Aligned( bonetoworld.GetBone( pbones[ibone].parent ), bonematrix, bonetoworld.GetBoneForWrite( ibone ) );
}