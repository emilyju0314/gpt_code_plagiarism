void DoAxisInterpBone(
	const mstudiobone_t		*pbones,
	int	ibone,
	CBoneAccessor &bonetoworld
	)
{
	BONE_PROFILE_FUNC();
	matrix3x4a_t	bonematrix;
	Vector				control;

	mstudioaxisinterpbone_t *pProc = (mstudioaxisinterpbone_t *)pbones[ibone].pProcedure( );
	const matrix3x4_t &controlBone = bonetoworld.GetBone( pProc->control );
	if (pProc && pbones[pProc->control].parent != -1)
	{
		Vector tmp;
		// pull out the control column
		tmp.x = controlBone[0][pProc->axis];
		tmp.y = controlBone[1][pProc->axis];
		tmp.z = controlBone[2][pProc->axis];

		// invert it back into parent's space.
		VectorIRotate( tmp, bonetoworld.GetBone( pbones[pProc->control].parent ), control );
#if 0
		matrix3x4a_t	tmpmatrix;
		matrix3x4a_t	controlmatrix;
		MatrixInvert( bonetoworld.GetBone( pbones[pProc->control].parent ), tmpmatrix );
		ConcatTransforms_Aligned( tmpmatrix, bonetoworld.GetBone( pProc->control ), controlmatrix );

		// pull out the control column
		control.x = controlmatrix[0][pProc->axis];
		control.y = controlmatrix[1][pProc->axis];
		control.z = controlmatrix[2][pProc->axis];
#endif
	}
	else
	{
		// pull out the control column
		control.x = controlBone[0][pProc->axis];
		control.y = controlBone[1][pProc->axis];
		control.z = controlBone[2][pProc->axis];
	}

	Quaternion *q1, *q2, *q3;
	Vector *p1, *p2, *p3;

	// find axial control inputs
	float a1 = control.x;
	float a2 = control.y;
	float a3 = control.z;
	if (a1 >= 0) 
	{ 
		q1 = &pProc->quat[0];
		p1 = &pProc->pos[0];
	} 
	else 
	{ 
		a1 = -a1; 
		q1 = &pProc->quat[1];
		p1 = &pProc->pos[1];
	}

	if (a2 >= 0) 
	{ 
		q2 = &pProc->quat[2]; 
		p2 = &pProc->pos[2];
	} 
	else 
	{ 
		a2 = -a2; 
		q2 = &pProc->quat[3]; 
		p2 = &pProc->pos[3];
	}

	if (a3 >= 0) 
	{ 
		q3 = &pProc->quat[4]; 
		p3 = &pProc->pos[4];
	} 
	else 
	{ 
		a3 = -a3; 
		q3 = &pProc->quat[5]; 
		p3 = &pProc->pos[5];
	}

	// do a three-way blend
	Vector p;
	Quaternion v, tmp;
	if (a1 + a2 > 0)
	{
		float t = 1.0 / (a1 + a2 + a3);
		// FIXME: do a proper 3-way Quat blend!
		QuaternionSlerp( *q2, *q1, a1 / (a1 + a2), tmp );
		QuaternionSlerp( tmp, *q3, a3 * t, v );
		VectorScale( *p1, a1 * t, p );
		VectorMA( p, a2 * t, *p2, p );
		VectorMA( p, a3 * t, *p3, p );
	}
	else
	{
		QuaternionSlerp( *q3, *q3, 0, v ); // ??? no quat copy?
		p = *p3;
	}

	QuaternionMatrix( v, p, bonematrix );

	ConcatTransforms (bonetoworld.GetBone( pbones[ibone].parent ), bonematrix, bonetoworld.GetBoneForWrite( ibone ));
}