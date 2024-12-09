void RigidBody::applyWorldForceAtCenterOfMass(const Vector3& force) {

    // If it is not a dynamic body, we do nothing
    if (mWorld.mRigidBodyComponents.getBodyType(mEntity) != BodyType::DYNAMIC) return;

    // Awake the body if it was sleeping
    if (mWorld.mRigidBodyComponents.getIsSleeping(mEntity)) {
        setIsSleeping(false);
    }

    // Add the force
    const Vector3& externalForce = mWorld.mRigidBodyComponents.getExternalForce(mEntity);
    mWorld.mRigidBodyComponents.setExternalForce(mEntity, externalForce + force);
}