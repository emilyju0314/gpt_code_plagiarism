void CPlayerController::Update(const Vector &position, const Vector &velocity, float secondsToArrival, bool onground, IPhysicsObject *pGround) {
	btVector3 bullTargetPosition, bullMaxVelocity;

	ConvertPosToBull(position, bullTargetPosition);
	ConvertPosToBull(velocity, bullMaxVelocity);

	// Reset the ticks since update counter
	m_ticksSinceUpdate = 0;

	// If the targets haven't changed, abort.
	if (bullMaxVelocity.distance2(m_maxVelocity) < FLT_EPSILON && bullTargetPosition.distance2(m_targetPosition) < FLT_EPSILON) {
		return;
	}

	// FIXME: If we're walking on a physics object, the game's input position DOES NOT FACTOR IN the base velocity of the
	// physics object!
	// Target position is just the target velocity integrated into our current position via the timestep
	m_targetPosition = bullTargetPosition;
	m_maxVelocity = bullMaxVelocity;

	// FYI: The onground stuff includes any props we may be standing on as well as the world.
	// The ground object is non-NULL only if it's significantly heavier than our object ("Rideable physics" > our mass * 2)
	m_onground = onground;

	m_enable = true;
	if (velocity.LengthSqr() <= 0.1f) {
		m_enable = false; // No input velocity, just go where physics takes you
		pGround = NULL;
	} else {
		MaxSpeed(velocity);
	}
	
	ConvertPosToBull(velocity, m_inputVelocity);

	m_secondsToArrival = secondsToArrival;

	// Detach ourselves from any existing ground
	if (m_pGround)
		m_pGround->DetachEventListener(this);

	m_pGround = (CPhysicsObject *)pGround;

	if (m_pGround) {
		// Attach ourself to the ground so we can listen to see if it gets destroyed
		m_pGround->AttachEventListener(this);

		// Where we are relative to the ground
		m_groundPos = m_pGround->GetObject()->getWorldTransform().inverse() * m_targetPosition;
	}
}