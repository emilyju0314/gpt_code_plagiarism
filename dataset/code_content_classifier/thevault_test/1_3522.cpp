void CPhysicsEnvironment::TickCallback(btDynamicsWorld *world, btScalar timeStep) {
	if (!world) return;

	CPhysicsEnvironment *pEnv = static_cast<CPhysicsEnvironment*>(world->getWorldUserInfo());
	if (pEnv)
		pEnv->BulletTick(timeStep);
}