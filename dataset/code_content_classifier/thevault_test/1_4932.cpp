void RigidBody::applyWorldForceAtWorldPosition(const Vector3& force, const Vector3& point) {

    // If it is not a dynamic body, we do nothing
    if (mWorld.mRigidBodyComponents.getBodyType(mEntity) != BodyType::DYNAMIC) return;

    // Awake the body if it was sleeping
    if (mWorld.mRigidBodyComponents.getIsSleeping(mEntity)) {
        setIsSleeping(false);
    }

    // Add the force
    const Vector3& externalForce = mWorld.mRigidBodyComponents.getExternalForce(mEntity);
    mWorld.mRigidBodyComponents.setExternalForce(mEntity, externalForce + force);

    // Add the torque
    const Vector3& externalTorque = mWorld.mRigidBodyComponents.getExternalTorque(mEntity);
    const Vector3& centerOfMassWorld = mWorld.mRigidBodyComponents.getCenterOfMassWorld(mEntity);
    mWorld.mRigidBodyComponents.setExternalTorque(mEntity, externalTorque + (point - centerOfMassWorld).cross(force));
}