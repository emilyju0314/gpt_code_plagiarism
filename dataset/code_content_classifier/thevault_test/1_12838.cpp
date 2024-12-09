void FemPhysicsCorotationalElasticity::StepExplicit(real h)
	{
		PROFILE_SCOPE("CR explicit");
		size_t numNodes = GetNumFreeNodes();

		ComputeRotations();
		ComputeElasticForces(mElasticForce);

		// add the gravity forces
		EigenVector f = ComputeLoadingForces() - mElasticForce;

		// solve the linear system for the accelerations (invert the mass matrix) 
		EigenVector sol = mExplicitMassSolver.Solve(f);
		Vector3Array a = GetStdVector(sol);

		// apply the forces and integrate (Symplectic Euler)
		for (size_t i = 0; i < numNodes; i++)
		{
			mVelocities[i] += h * a[i];
			mDeformedPositions[i] += h * mVelocities[i];
		}
	}