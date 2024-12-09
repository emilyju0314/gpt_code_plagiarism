void CPhysicsConstraint::ObjectDestroyed(CPhysicsObject *pObject) {
	if (pObject != m_pAttachedObject && pObject != m_pReferenceObject) {
		AssertMsg(0, "ObjectDestroyed called with object that isn't part of this constraint!");
		return;
	}

	if (pObject == m_pAttachedObject)
		m_pAttachedObject = NULL;

	if (pObject == m_pReferenceObject)
		m_pReferenceObject = NULL;

	// Constraint is no longer valid due to one of its objects being removed, so stop simulating it.
	bool notify = false; // Don't run the callback more than once!
	if (!m_bRemovedFromEnv) {
		m_pEnv->GetBulletEnvironment()->removeConstraint(m_pConstraint);
		m_bRemovedFromEnv = true;
		notify = true;

		if (m_type == CONSTRAINT_USER)
			((btUserConstraint *)m_pConstraint)->getUserConstraint()->ConstraintDestroyed(this);
	}

	// Tell the game that this constraint was broken.
	if (notify && m_bNotifyBroken)
		m_pEnv->HandleConstraintBroken(this);
}