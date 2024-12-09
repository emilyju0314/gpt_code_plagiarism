void InitPose(
	const CStudioHdr *pStudioHdr,
	BoneVector pos[], 
	BoneQuaternionAligned q[],
	int boneMask 
	)
{
	// const fltx4 zeroQ = Four_Origin;
	BONE_PROFILE_FUNC();
	SNPROF_ANIM("InitPose");

	if( mstudiolinearbone_t *pLinearBones = pStudioHdr->pLinearBones() )
	{
		int numBones = pStudioHdr->numbones();

		Assert( sizeof(Quaternion) == sizeof(BoneQuaternion) );
		memcpy( q, (((byte *)pLinearBones) + pLinearBones->quatindex), sizeof( Quaternion ) * numBones );

		if( sizeof(Vector) == sizeof(BoneVector) )
		{
			memcpy( pos, (((byte *)pLinearBones) + pLinearBones->posindex), sizeof( Vector ) * numBones );
		}
		else
		{
			Vector *pSrcPos = (Vector *)(((byte *)pLinearBones) + pLinearBones->posindex);
			for( int i = 0; i < pStudioHdr->numbones(); i++ )
			{
				//if( pStudioHdr->boneFlags(  i ) & boneMask ) 
				{
					pos[i] = pSrcPos[i];
				}
			}
		}
	}
	else
	{
		for( int i = 0; i < pStudioHdr->numbones(); i++ )
		{
			if( pStudioHdr->boneFlags(  i ) & boneMask )  
			{
				const mstudiobone_t *pbone = pStudioHdr->pBone( i );
				pos[i] = pbone->pos;
				q[i] = pbone->quat;
			}
			/* // unnecessary to initialize unused bones since they are ignored downstream.
			else
			{
				pos[i].Zero();
				// q[i] = zeroQ;
				StoreAlignedSIMD(q[i].Base(), zeroQ);
			}
			*/
		}
	}
}