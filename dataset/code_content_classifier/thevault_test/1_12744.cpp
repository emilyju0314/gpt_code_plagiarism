void Physics_ParticleSystem::Update_Explicit( float fTime )
{
	m_real fTotal = 0.0f, fStep = (m_real)fTime;
	vector3 vCOG, dTorque, tmp, tmp2;
	int i;

	while( fTotal < fTime )
	{
		// 
		// Zero out everything
		//
		m_TotalForces_int.zero(); m_TotalForces_ext.zero();


		//
		// Apply the forces
		//
		for(int i=0, ni=m_Forces.size(); i<ni; i++) {
			m_Forces[i]->Apply(fStep, m_Masses, false, m_Positions,
					m_Velocities, m_TotalForces_int, m_TotalForces_ext,
					m_TotalForces_dp, m_TotalForces_dv ); }


		//
		// Compute the new velocities and positions
		//
		m_TotalForces_ext.Add( m_TotalForces_int, m_vTemp1 );
		m_vTemp1.ElementMultiply( m_MassInv, m_dv ); m_dv.Scale( fStep, m_dv );
		m_Velocities.Add( m_dv, m_Velocities ); m_Velocities.Scale( fStep,
				m_vTemp1 ); m_Positions.Add( m_vTemp1, m_PosTemp );

		//
		// Apply inverse dynamics to prevent excessive stretch We need 10 or so
		// iterations to be stable -- with more particles in the mesh, we need
		// more iterations.
		//
		for( i=0; i<m_iInverseIterations; i++ ) { for(int i=0,
				ni=m_Forces.size(); i<ni; i++) { m_Forces[i]->Fixup( m_Masses,
				m_PosTemp ); } }
		//
		// Update velocity and position
		//
		m_PosTemp.Subtract( m_Positions, m_vTemp1 ); m_vTemp1.Scale(
				(m_real)1.0 / fStep, m_Velocities );
		/*for( i=0; i<m_iParticles; i++ )
		  if( m_PosTemp[i].y < FLOOR_Y ) { m_PosTemp[i].y = FLOOR_Y;
		  m_Velocities[i].y = 0; }*/ m_Positions = m_PosTemp;

		fTotal += (m_real)fabs( fStep ); 
	} 
}