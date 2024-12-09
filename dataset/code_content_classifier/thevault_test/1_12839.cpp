void FemPhysicsCorotationalElasticity::AssembleStiffnessMatrix()
	{
		PROFILE_SCOPE("CR assemble");
		size_t numNodes = GetNumFreeNodes();
		size_t numDofs = numNodes * NUM_POS_COMPONENTS;
		if (mDenseK.rows() != numDofs)
			mDenseK.resize(numDofs, numDofs);
		mDenseK.setZero();
		EigenMatrix Rlocal;
		Rlocal.resize(GetNumLocalNodes() * NUM_POS_COMPONENTS, GetNumLocalNodes() * NUM_POS_COMPONENTS);
		mCachedRotationMatrix.resize(GetNumElements());
		for (size_t i = 0; i < (size_t)mTetMesh->GetNumElements(); i++)
		{
			EigenMatrix Klocal = mCachedLocalStiffnessMatrix[i];
			Matrix3R R = mCachedRotationMatrix[i];

			// convert the 3x3 rotation matrix to Eigen
			EigenMatrix Reig = Matrix3ToEigen<EigenMatrix>(R);

			// build the element matrix with diagonal blocks equal to R
			Rlocal.setZero();
			for (size_t j = 0; j < GetNumLocalNodes(); j++)
			{
				Rlocal.block<NUM_POS_COMPONENTS, NUM_POS_COMPONENTS>(j * NUM_POS_COMPONENTS, j * NUM_POS_COMPONENTS) = Reig;
			}

			// compute the element locally rotated stiffness matrix
			EigenMatrix Klocal_rot = Rlocal * Klocal * Rlocal.transpose();

			// the local stiffness matrix Klocal is organized in 3x3 blocks for each pair of nodes
			for (size_t j = 0; j < GetNumLocalNodes(); j++)
			{
				size_t jGlobal = mReshuffleMap[mTetMesh->GetGlobalIndex(i, j)];
				if (jGlobal < mNumBCs)
					continue;
				for (size_t k = 0; k < GetNumLocalNodes(); k++)
				{
					size_t kGlobal = mReshuffleMap[mTetMesh->GetGlobalIndex(i, k)];
					if (kGlobal < mNumBCs)
						continue;
					int jOffset = (jGlobal - mNumBCs) * NUM_POS_COMPONENTS;
					int kOffset = (kGlobal - mNumBCs) * NUM_POS_COMPONENTS;

					// add the the whole 3x3 block to the block matrix
					for (uint32 x = 0; x < NUM_POS_COMPONENTS; x++)
					{
						for (uint32 y = 0; y < NUM_POS_COMPONENTS; y++)
						{
							mDenseK.coeffRef(jOffset + x, kOffset + y) += Klocal_rot(j * NUM_POS_COMPONENTS + x, k * NUM_POS_COMPONENTS + y);
						}
					}
				}
			}
		}

		mStiffnessMatrix = mDenseK.sparseView();
	}