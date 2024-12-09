int CPlayerController::GetShadowPosition(Vector *position, QAngle *angles) {
	btRigidBody *pObject = m_pObject->GetObject();

	btTransform transform;
	((btMassCenterMotionState *)pObject->getMotionState())->getGraphicTransform(transform);

	if (position) ConvertPosToHL(transform.getOrigin(), *position);
	if (angles) ConvertRotationToHL(transform.getBasis(), *angles);

	// Yep. We're returning a variable totally unrelated to the shadow's position.
	// Returns whether the physics object was updated this frame or not
	return 1;
}