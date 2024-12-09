void RigidBody::resetForce() {

    // If it is not a dynamic body, we do nothing
    if (mWorld.mRigidBodyComponents.getBodyType(mEntity) != BodyType::DYNAMIC) return;

    // Set the external force to zero
    mWorld.mRigidBodyComponents.setExternalForce(mEntity, Vector3(0, 0, 0));
}