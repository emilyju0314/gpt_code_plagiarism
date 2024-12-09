void RigidBody::resetTorque() {

    // If it is not a dynamic body, we do nothing
    if (mWorld.mRigidBodyComponents.getBodyType(mEntity) != BodyType::DYNAMIC) return;

    // Set the external torque to zero
    mWorld.mRigidBodyComponents.setExternalTorque(mEntity, Vector3(0, 0, 0));
}