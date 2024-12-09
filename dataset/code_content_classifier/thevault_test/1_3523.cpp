void CPhysicsEnvironment::DoCollisionEvents(float dt) {
	if (m_pCollisionEvent) {
		const int numManifolds = m_pBulletDynamicsWorld->getDispatcher()->getNumManifolds();
		for (int i = 0; i < numManifolds; i++) {
			btPersistentManifold *contactManifold = m_pBulletDynamicsWorld->getDispatcher()->getManifoldByIndexInternal(i);
			if (contactManifold->getNumContacts() <= 0)
				continue;

			const btCollisionObject *obA = contactManifold->getBody0();
			const btCollisionObject *obB = contactManifold->getBody1();
			if (!obA || !obB) continue;

			CPhysicsObject *physObA = static_cast<CPhysicsObject*>(obA->getUserPointer());
			CPhysicsObject *physObB = static_cast<CPhysicsObject*>(obB->getUserPointer());

			// These are our own internal objects, don't do callbacks on them.
			if (obA->getInternalType() == btCollisionObject::CO_GHOST_OBJECT || obB->getInternalType() == btCollisionObject::CO_GHOST_OBJECT)
				continue;

			if (!(physObA->GetCallbackFlags() & CALLBACK_GLOBAL_FRICTION)  || !(physObB->GetCallbackFlags() & CALLBACK_GLOBAL_FRICTION))
				continue;

			for (int j = 0; j < contactManifold->getNumContacts(); j++) {
				btManifoldPoint manPoint = contactManifold->getContactPoint(j);

				// FRICTION CALLBACK
				// FIXME: We need to find the energy used by the friction! Bullet doesn't provide this in the manifold point.
				// This may not be the proper variable but whatever, as of now it works.
				const float energy = abs(manPoint.m_appliedImpulseLateral1);
				if (energy > 0.05f) {
					CPhysicsCollisionData data(&manPoint);
					m_pCollisionEvent->Friction(static_cast<CPhysicsObject*>(obA->getUserPointer()),
												ConvertEnergyToHL(energy),
												static_cast<CPhysicsObject*>(obA->getUserPointer())->GetMaterialIndex(),
												static_cast<CPhysicsObject*>(obB->getUserPointer())->GetMaterialIndex(),
												&data);
				}

				// TODO: Collision callback
				// Source wants precollision and postcollision callbacks (pre velocity and post velocity, etc.)
				// How do we generate a callback before the collision happens?
			}
		}
	}
}