void FemPhysicsMatrixFree::SubStep(real h)
	{
		for (uint32 i = 0; i < mForces.size(); i++)
			mForces[i].SetZero();
		ElasticEnergy::ComputeForces(this, mForces);

		ComputeSpringForces(mForces);

		// integrate node velocities and positions using Symplectic Euler
		for (size_t i = 0; i < nodes.size(); i++)
		{
			if (nodes[i].invMass == 0)
				continue;
			nodes[i].vel += (h * nodes[i].invMass) * mForces[i] + h * mGravity;
			nodes[i].pos += h * nodes[i].vel;
		}
	}