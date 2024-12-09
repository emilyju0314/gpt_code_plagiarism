void RigidBody::setTransform(const Transform& transform) {

    const Vector3 oldCenterOfMass = mWorld.mRigidBodyComponents.getCenterOfMassWorld(mEntity);

    // Compute the new center of mass in world-space coordinates
    const Vector3& centerOfMassLocal = mWorld.mRigidBodyComponents.getCenterOfMassLocal(mEntity);
    mWorld.mRigidBodyComponents.setCenterOfMassWorld(mEntity, transform * centerOfMassLocal);

    // Update the linear velocity of the center of mass
    Vector3 linearVelocity = mWorld.mRigidBodyComponents.getLinearVelocity(mEntity);
    const Vector3& angularVelocity = mWorld.mRigidBodyComponents.getAngularVelocity(mEntity);
    const Vector3& centerOfMassWorld = mWorld.mRigidBodyComponents.getCenterOfMassWorld(mEntity);
    linearVelocity += angularVelocity.cross(centerOfMassWorld - oldCenterOfMass);
    mWorld.mRigidBodyComponents.setLinearVelocity(mEntity, linearVelocity);

    CollisionBody::setTransform(transform);

    // Awake the body if it is sleeping
    setIsSleeping(false);
}