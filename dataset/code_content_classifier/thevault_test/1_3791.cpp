void CPhysicsObject::OutputDebugInfo() const
{
	Msg("-----------------\nObject: %s\n", m_pObject->get_name());
	Msg("Mass: %.1f (inv %.3f)\n", GetMass(), GetInvMass() );
	Vector inertia = GetInertia();
	Vector invInertia = GetInvInertia();
	Msg("Inertia: %.2f, %.2f, %.2f (inv %.3f, %.3f, %.3f)\n", inertia.x, inertia.y, inertia.z, invInertia.x, invInertia.y, invInertia.z );

	Vector speed, angSpeed;
	GetVelocity( &speed, &angSpeed );
	Msg("Velocity: %.2f, %.2f, %.2f \n", speed.x, speed.y, speed.z );
	Msg("Ang Velocity: %.2f, %.2f, %.2f \n", angSpeed.x, angSpeed.y, angSpeed.z );

	float damp, angDamp;
	GetDamping( &damp, &angDamp );
	Msg("Damping %.2f linear, %.2f angular\n", damp, angDamp );

	Msg("Linear Drag: %.2f, %.2f, %.2f (factor %.2f)\n", m_dragBasis.x, m_dragBasis.y, m_dragBasis.z, m_dragCoefficient );
	Msg("Angular Drag: %.2f, %.2f, %.2f (factor %.2f)\n", m_angDragBasis.x, m_angDragBasis.y, m_angDragBasis.z, m_angDragCoefficient );

	if ( IsHinged() )
	{
		const char *pAxisNames[] = {"x", "y", "z"};
		Msg("Hinged on %s axis\n", pAxisNames[m_hingedAxis-1] );
	}
	Msg("attached to %d controllers\n", m_pObject->get_core()->controllers_of_core.len() );
	for (int k = m_pObject->get_core()->controllers_of_core.len()-1; k>=0;k--)
	{
		// NOTE: Set a breakpoint here and take a look at what it's hooked to
		IVP_Controller *pController = m_pObject->get_core()->controllers_of_core.element_at(k);
		Msg("%d) %s\n", k, pController->get_controller_name() );
	}
	Msg("State: %s, Collision %s, Motion %s, %sFlags %04X (game %04x, index %d)\n", 
		IsAsleep() ? "Asleep" : "Awake",
		IsCollisionEnabled() ? "Enabled" : "Disabled",
		IsStatic() ? "Static" : (IsMotionEnabled() ? "Enabled" : "Disabled"),
		(GetCallbackFlags() & CALLBACK_MARKED_FOR_TEST) ? "Debug! " : "",
		(int)GetCallbackFlags(), (int)GetGameFlags(), (int)GetGameIndex() );

	float matDensity = 0;
	float matThickness = 0;
	float matFriction = 0;
	float matElasticity = 0;
	physprops->GetPhysicsProperties( GetMaterialIndexInternal(), &matDensity, &matThickness, &matFriction, &matElasticity );
	Msg("Material: %s : density(%.1f), thickness(%.2f), friction(%.2f), elasticity(%.2f)\n", physprops->GetPropName(GetMaterialIndexInternal()),
		matDensity, matThickness, matFriction, matElasticity );
	if ( GetCollide() )
	{
		OutputCollideDebugInfo( GetCollide() );
	}
}