void CPhysicsObject::BecomeHinged( int localAxis )
{
	if ( IsMoveable() )
	{
		float savedMass = GetMass();

		IVP_U_Float_Hesse *iri = (IVP_U_Float_Hesse *)m_pObject->get_core()->get_inv_rot_inertia();

		float savedRI[3];
		for ( int i = 0; i < 3; i++ )
			savedRI[i] = iri->k[i];

		SetMass( VPHYSICS_MAX_MASS );
		IVP_U_Float_Hesse tmp = *iri;
#if 0
		for ( i = 0; i < 3; i++ )
			tmp.k[i] = savedRI[i];
#else
		int localAxisIVP = ConvertCoordinateAxisToIVP(localAxis);
		tmp.k[localAxisIVP] = savedRI[localAxisIVP];
#endif

		SetMass( savedMass );
		*iri = tmp;
	}
	m_hingedAxis = localAxis+1;
}