void FemPhysicsLinearElasticity::AssembleStiffnessMatrix()
	{
		size_t numNodes = GetNumFreeNodes(); // remove the first 4 entries which are fixed (hack)
		size_t numDofs = numNodes * 3;
		mStiffnessMatrix.resize(numDofs, numDofs);
		mStiffnessMatrix.setZero();
		mBCStiffnessMatrix.resize(numDofs, mNumBCs * 3);
		mBCStiffnessMatrix.setZero();
		// go through all linear elements (tetrahedra)
		for (size_t i = 0; i < (size_t)mTetMesh->GetNumElements(); i++)
		{
			EigenMatrix Klocal;
			ComputeLocalStiffnessMatrixBB(i, GetShearModulus(), GetLameFirstParam(), Klocal);
			// the local stiffness matrix Klocal is organized in 3x3 blocks for each pair of nodes
			for (size_t j = 0; j < GetNumLocalNodes(); j++)
			{
				size_t jGlobal = mReshuffleMap[mTetMesh->GetGlobalIndex(i, j)];
				for (size_t k = 0; k < GetNumLocalNodes(); k++)
				{
					size_t kGlobal = mReshuffleMap[mTetMesh->GetGlobalIndex(i, k)];
					if (jGlobal < mNumBCs)
						continue;
					int jOffset = (jGlobal - mNumBCs) * NUM_POS_COMPONENTS;
					int kOffset = (kGlobal - mNumBCs) * NUM_POS_COMPONENTS;

					// add the the whole 3x3 block to the block matrix
					for (size_t x = 0; x < NUM_POS_COMPONENTS; x++)
					{
						for (size_t y = 0; y < NUM_POS_COMPONENTS; y++)
						{
							real val = Klocal(j * NUM_POS_COMPONENTS + x, k * NUM_POS_COMPONENTS + y);
							if (kGlobal < mNumBCs)
							{
								mBCStiffnessMatrix.coeffRef(jOffset + x, kGlobal * NUM_POS_COMPONENTS + y) += val;
							}
							else
							{
								mStiffnessMatrix.coeffRef(jOffset + x, kOffset + y) += val;
							}
						}
					}
				}
			}
		}
	}