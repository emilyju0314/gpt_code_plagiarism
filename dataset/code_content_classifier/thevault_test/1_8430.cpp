void CWretch::VPhysicsCollision( int index, gamevcollisionevent_t *pEvent )
{
	// Only do the override while riding on a vehicle
	if ( m_PassengerBehavior.CanSelectSchedule() && m_PassengerBehavior.GetPassengerState() != PASSENGER_STATE_OUTSIDE )
	{
		int damageType = 0;
		float flDamage = CalculatePhysicsImpactDamage( index, pEvent, gZombiePassengerImpactDamageTable, 1.0, true, damageType );

		if ( flDamage > 0  )
		{
			Vector damagePos;
			pEvent->pInternalData->GetContactPoint( damagePos );
			Vector damageForce = pEvent->postVelocity[index] * pEvent->pObjects[index]->GetMass();
			CTakeDamageInfo info( this, this, damageForce, damagePos, flDamage, (damageType|DMG_VEHICLE) );
			TakeDamage( info );
		}
		return;
	}

	BaseClass::VPhysicsCollision( index, pEvent );
}