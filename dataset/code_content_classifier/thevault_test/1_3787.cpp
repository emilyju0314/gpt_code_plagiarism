void CPhysicsObject::ApplyForceCenter( const Vector &forceVector )
{
	if ( !IsMoveable() )
		return;

	IVP_U_Float_Point tmp;

	ConvertForceImpulseToIVP( forceVector, tmp );
	IVP_Core *core = m_pObject->get_core();
	tmp.mult( core->get_inv_mass() );
	m_pObject->async_add_speed_object_ws( &tmp );
	ClampVelocity();
}