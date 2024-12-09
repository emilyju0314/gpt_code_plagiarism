void CPhysicsObject::CalculateVelocityOffset(const Vector &forceVector, const Vector &worldPosition, Vector *centerVelocity, AngularImpulse *centerAngularVelocity) const {
	if (!centerVelocity && !centerAngularVelocity) return;

	btVector3 force, relpos;
	ConvertForceImpulseToBull(forceVector, force);
	ConvertPosToBull(worldPosition, relpos);

	relpos -= m_pObject->getCenterOfMassPosition();

	// Relative pos cross normal
	btVector3 cross = relpos.cross(force);

	// Linear velocity
	if (centerVelocity) {
		force *= m_pObject->getInvMass();
		ConvertForceImpulseToHL(force, *centerVelocity);
	}

	if (centerAngularVelocity) {
		// Convert to local space and give it to the game (game rotations in local space)
		cross = m_pObject->getWorldTransform().getBasis().transpose() * cross;
		ConvertAngularImpulseToHL(cross, *centerAngularVelocity);
	}
}