void FemPhysicsLinearElasticity::StepExplicit(real h)
	{
		// TODO: avoid allocations by using class data members

		// compute nodal displacements and aggregate them into one big vector
		size_t numNodes = GetNumFreeNodes();
		Vector3Array u(numNodes);
		for (size_t i = 0; i < numNodes; i++)
		{
			u[i] = mDeformedPositions[i] - mReferencePositions[i + mNumBCs];
		}

		// compute the elastic forces using the linear elasticity relation f = Ku
		// (when using explicit time integration we don't really need to assemble the K matrix - see ComputeForces(),
		// but it's good to have it for other purposes, e.g. damping, implicit integration, quasi-static simulation)
		EigenVector f = -mStiffnessMatrix * GetEigenVector(u);

		// add the gravity forces
		f += ComputeLoadingForces();

		// solve the linear system for the accelerations (invert the mass matrix) 
		EigenVector sol = mSparseLU.solve(f);
		Vector3Array a = GetStdVector(sol);

		// apply the forces and integrate (Symplectic Euler)
		for (size_t i = 0; i < numNodes; i++)
		{
			mVelocities[i] += h * a[i];
			mDeformedPositions[i] += h * mVelocities[i];
		}
	}