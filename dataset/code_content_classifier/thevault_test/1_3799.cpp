CPhysicsObject *CPlayerController::GetGroundObject() {
	btDispatcher *pDispatcher = m_pEnv->GetBulletEnvironment()->getDispatcher();

	// Loop through the collision pair manifolds
	int numManifolds = pDispatcher->getNumManifolds();
	for (int i = 0; i < numManifolds; i++) {
		btPersistentManifold *pManifold = pDispatcher->getManifoldByIndexInternal(i);
		if (pManifold->getNumContacts() <= 0)
			continue;

		const btCollisionObject *objA = pManifold->getBody0();
		const btCollisionObject *objB = pManifold->getBody1();

		// Skip if one object is static/kinematic
		if (objA->isStaticOrKinematicObject() || objB->isStaticOrKinematicObject())
			continue;

		CPhysicsObject *pPhysA = (CPhysicsObject *)objA->getUserPointer();
		CPhysicsObject *pPhysB = (CPhysicsObject *)objB->getUserPointer();

		// Collision that involves us!
		if (objA == m_pObject->GetObject() || objB == m_pObject->GetObject()) {
			int ourID = m_pObject->GetObject() == objA ? 0 : 1;

			for (int i = 0; i < pManifold->getNumContacts(); i++) {
				btManifoldPoint &point = pManifold->getContactPoint(i);

				btVector3 norm = point.m_normalWorldOnB; // Normal worldspace A->B
				if (ourID == 1) {
					// Flip it because we're object B and we need norm B->A.
					norm *= -1;
				}

				// HACK: Guessing which way is up (as currently defined in our implementation y is up)
				// If the normal is up enough then assume it's some sort of ground
				if (norm.y() > 0.8) {
					return ourID == 0 ? pPhysB : pPhysA;
				}
			}
		}
	}

	return NULL;
}