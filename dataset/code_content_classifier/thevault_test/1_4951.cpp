void RigidBody::applyWorldTorque(const Vector3& torque) {

    // If it is not a dynamic body, we do nothing
    if (mWorld.mRigidBodyComponents.getBodyType(mEntity) != BodyType::DYNAMIC) return;

    // Awake the body if it was sleeping
    if (mWorld.mRigidBodyComponents.getIsSleeping(mEntity)) {
        setIsSleeping(false);
    }

    // Add the torque
    const Vector3& externalTorque = mWorld.mRigidBodyComponents.getExternalTorque(mEntity);
    mWorld.mRigidBodyComponents.setExternalTorque(mEntity, externalTorque + torque);
}