void CPlayerController::MaxSpeed(const Vector &hlMaxVelocity) {
	btVector3 maxVel;
	ConvertPosToBull(hlMaxVelocity, maxVel);
	btVector3 available = maxVel;
	
	float maxVelLen = maxVel.length();
	maxVel.normalize();
	
	// Only if we're headed in the same direction as maxVelocity
	float dot = maxVel.dot(m_pObject->GetObject()->getLinearVelocity()); // Magnitude of our speed in the same direction as maxVel
	if (dot > 0) {
		maxVel *= dot * maxVelLen; // maxVel(normalized) *= dot(maxVel(norm), linVel) * len(maxVel)
		available -= maxVel; // Now subtract the magnitude of our current speed along the maxVelocity vector
	}
	
	m_maxSpeed = available.absolute();
}